import requests
import json
from datetime import datetime
import subprocess
import os
import shutil
import time


# ================= CONFIGURATION =================
LEETCODE_USERNAME = os.getenv("LEETCODE_USERNAME_")
LEETCODE_SESSION_COOKIE = os.getenv("LEETCODE_SESSION_COOKIE_")  
GITHUB_REPO_URL = os.getenv("GITHUB_REPO_URL_")
LOCAL_REPO_DIR = os.getenv("LOCAL_REPO_DIR_")
# =================================================

LANG_EXTENSIONS = {
    "cpp": "cpp", "python": "py", "python3": "py", "java": "java",
    "c": "c", "csharp": "cs", "javascript": "js", "typescript": "ts",
    "golang": "go", "rust": "rs", "kotlin": "kt", "sql": "sql"
}
# =================================================

def fetch_all_submissions(username, session_cookie, total_fetch=900):
    """
    Paginates through submission history to fetch beyond the default 20 limit.
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
    limit = 20
    last_key = None

    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
        "Cookie": f"LEETCODE_SESSION={session_cookie}"
    }

    print("1. Fetching full submission history...")
    while len(all_submissions) < total_fetch:
        variables = {"offset": offset, "limit": limit, "lastKey": last_key}
        response = requests.post(url, json={"query": query, "variables": variables}, headers=headers)
        
        if response.status_code != 200:
            print(f"Error fetching page at offset {offset}")
            break

        data = response.json().get('data', {}).get('submissionList', {})
        submissions = data.get('submissions', [])
        
        # Keep only Accepted submissions
        accepted = [s for s in submissions if s.get('statusDisplay') == 'Accepted']
        all_submissions.extend(accepted)
        
        if not data.get('hasNext'):
            break

        offset += limit
        last_key = data.get('lastKey')
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
    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
        "Cookie": f"LEETCODE_SESSION={session_cookie}"
    }
    response = requests.post(url, json={"query": query, "variables": {"submissionId": int(submission_id)}}, headers=headers)
    if response.status_code == 200:
        data = response.json().get('data', {}).get('submissionDetails')
        if data:
            return data.get('code'), data.get('lang', {}).get('name')
    return None, None

def reset_and_setup_repo():
    """Wipes local repo folder to clear old .md files and re-initializes git."""
    if os.path.exists(LOCAL_REPO_DIR):
        shutil.rmtree(LOCAL_REPO_DIR)
    
    os.makedirs(LOCAL_REPO_DIR)
    os.chdir(LOCAL_REPO_DIR)
    
    subprocess.run(["git", "init", "-b", "main"])
    subprocess.run(["git", "remote", "add", "origin", GITHUB_REPO_URL])
    subprocess.run(["git", "config", "user.email", "sourav2003singhkatoch@gmail.com"])
    subprocess.run(["git", "config", "user.name", "sipher-01"])

def run_sync():
    submissions = fetch_all_submissions(LEETCODE_USERNAME, LEETCODE_SESSION_COOKIE, total_fetch=900)
    print(f"Total Accepted Submissions Found: {len(submissions)}")

    reset_and_setup_repo()

    # Sort oldest first so commits are inserted in chronological order
    submissions.sort(key=lambda x: int(x['timestamp']))

    for sub in submissions:
        sub_id = sub['id']
        title_slug = sub['titleSlug']
        ts = int(sub['timestamp'])

        code, lang = get_submission_code(sub_id, LEETCODE_SESSION_COOKIE)
        if not code or not lang:
            continue

        ext = LANG_EXTENSIONS.get(lang.lower(), "txt")
        filename = f"{title_slug}.{ext}"

        with open(filename, "w", encoding="utf-8") as f:
            f.write(code)

        commit_date = datetime.fromtimestamp(ts).strftime("%Y-%m-%dT%H:%M:%S +0000")
        subprocess.run(["git", "add", filename])
        subprocess.run(["git", "commit", "-m", f"Solve {sub['title']} [{lang}]", "--date", commit_date])
        print(f"✓ Committed: {filename}")
        time.sleep(0.5)

    # Force push wipes old remote .md files and overwrites with the clean code-only branch
    print("Pushing to GitHub (overwriting old .md files)...")
    subprocess.run(["git", "push", "-u", "origin", "main", "--force"])
    print("Done!")

if __name__ == "__main__":
    run_sync()