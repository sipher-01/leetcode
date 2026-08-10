import argparse
from datetime import datetime
import json
import os
import requests
import shutil
import subprocess
import time

# ================= CONFIGURATION =================
LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME_")
LEETCODE_SESSION_COOKIE = os.getenv("LEETCODE_SESSION_COOKIE_")
REPO_URL = os.getenv("REPO_URL_")
LOCAL_REPO_DIR = os.getenv("LOCAL_REPO_DIR_", ".")
# =================================================

LANG_EXTENSIONS = {
    "cpp": "cpp", "python": "py", "python3": "py", "java": "java",
    "c": "c", "csharp": "cs", "javascript": "js", "typescript": "ts",
    "golang": "go", "rust": "rs", "kotlin": "kt", "sql": "sql"
}
# =================================================

def fetch_submissions(username, session_cookie, is_bulk=False, total_fetch=900):
    """
    In Daily Mode (is_bulk=False): Fetches ONLY 1 submission (the absolute latest).
    In Bulk Mode (is_bulk=True): Paginates history up to total_fetch.
    """
    url = "https://leetcode.com/graphql/"
    query = """
    query submissionList($offset: Int!, $limit: Int!, $lastKey: String) {
      submissionList(offset: $offset, limit: $limit, lastKey: $lastKey) {
        hasNext
        lastKey
        submissions {
          id
          title
          titleSlug
          statusDisplay
          timestamp
        }
      }
    }
    """
    
    all_submissions = []
    offset = 0
    # Single mode requests only 1 submission; Bulk mode requests 20 per page
    limit = 20 if is_bulk else 1
    last_key = None

    # Handle full "LEETCODE_SESSION=..." or raw session string cleanly
    cookie_header = session_cookie if (session_cookie and session_cookie.startswith("LEETCODE_SESSION=")) else f"LEETCODE_SESSION={session_cookie}"

    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
        "Cookie": cookie_header
    }

    print("Fetching submission history from LeetCode...")
    max_to_fetch = total_fetch if is_bulk else 1

    while len(all_submissions) < max_to_fetch:
        variables = {"offset": offset, "limit": limit, "lastKey": last_key}
        response = requests.post(url, json={"query": query, "variables": variables}, headers=headers)
        
        if response.status_code != 200:
            print(f"Error fetching page at offset {offset}: HTTP {response.status_code}")
            break

        res_json = response.json()
        data = res_json.get('data', {})
        submission_list = data.get('submissionList') if data else None

        # Guard against NoneType / Null API responses
        if not submission_list:
            print("Authentication failed or received null response from LeetCode. Check your session cookie.")
            break

        submissions = submission_list.get('submissions') or []
        
        # Filter for accepted submissions
        accepted = [s for s in submissions if s.get('statusDisplay') == 'Accepted']
        all_submissions.extend(accepted)
        
        # Stop immediately after 1 request if in daily mode or if no pages remain
        if not is_bulk or not submission_list.get('hasNext'):
            break

        offset += limit
        last_key = submission_list.get('lastKey')
        time.sleep(0.5)

    return all_submissions

def get_submission_code(submission_id, session_cookie):
    url = "https://leetcode.com/graphql/"
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        lang { name }
      }
    }
    """
    cookie_header = session_cookie if (session_cookie and session_cookie.startswith("LEETCODE_SESSION=")) else f"LEETCODE_SESSION={session_cookie}"

    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
        "Cookie": cookie_header
    }
    response = requests.post(url, json={"query": query, "variables": {"submissionId": int(submission_id)}}, headers=headers)
    if response.status_code == 200:
        data = response.json().get('data', {}).get('submissionDetails')
        if data:
            return data.get('code'), data.get('lang', {}).get('name')
    return None, None

def reset_and_setup_repo():
    """Wipes local repo folder and re-initializes git (Bulk Mode only)."""
    if os.path.exists(LOCAL_REPO_DIR) and LOCAL_REPO_DIR != ".":
        shutil.rmtree(LOCAL_REPO_DIR)
        os.makedirs(LOCAL_REPO_DIR)
    
    if LOCAL_REPO_DIR != ".":
        os.chdir(LOCAL_REPO_DIR)
    
    subprocess.run(["git", "init", "-b", "main"])
    if REPO_URL:
        subprocess.run(["git", "remote", "add", "origin", REPO_URL])
    subprocess.run(["git", "config", "user.email", "sourav2003singhkatoch@gmail.com"])
    subprocess.run(["git", "config", "user.name", "sipher-01"])

def run_sync(is_bulk=False):
    submissions = fetch_submissions(LEETCODE_USERNAME, LEETCODE_SESSION_COOKIE, is_bulk=is_bulk)
    print(f"Accepted Submissions Retrieved: {len(submissions)}")

    if not submissions:
        print("No valid accepted submissions found to sync.")
        return

    if is_bulk:
        print("Running in BULK mode. Re-initializing repository...")
        reset_and_setup_repo()
        submissions.sort(key=lambda x: int(x['timestamp']))
    else:
        print("Running in SINGLE/DAILY mode. Checking latest submission...")

    new_files_count = 0

    for sub in submissions:
        sub_id = sub['id']
        title_slug = sub['titleSlug']
        ts = int(sub['timestamp'])

        code, lang = get_submission_code(sub_id, LEETCODE_SESSION_COOKIE)
        if not code or not lang:
            continue

        ext = LANG_EXTENSIONS.get(lang.lower(), "txt")
        filename = f"{title_slug}.{ext}"

        # In single/daily mode, skip if already stored locally
        if not is_bulk and os.path.exists(filename):
            print(f"Latest submission already exists: {filename}")
            continue

        with open(filename, "w", encoding="utf-8") as f:
            f.write(code)

        new_files_count += 1

        if is_bulk:
            commit_date = datetime.fromtimestamp(ts).strftime("%Y-%m-%dT%H:%M:%S +0000")
            subprocess.run(["git", "add", filename])
            subprocess.run(["git", "commit", "-m", f"Solve {sub['title']} [{lang}]", "--date", commit_date])
            print(f"✓ Committed (Historical): {filename}")
        else:
            print(f"✓ Created/Updated latest solution: {filename}")

        time.sleep(0.5)

    if is_bulk:
        print("Pushing historical commits to GitHub (force overwriting)...")
        subprocess.run(["git", "push", "-u", "origin", "main", "--force"])
        print("Bulk Sync Done!")
    else:
        print(f"Daily Sync Complete. New files updated: {new_files_count}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="LeetCode Submission Sync")
    parser.add_argument(
        "--bulk", 
        action="store_true", 
        help="Run full historical bulk sync and re-initialize repo"
    )
    args = parser.parse_args()

    run_sync(is_bulk=args.bulk)