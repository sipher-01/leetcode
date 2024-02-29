class Solution {
public:
    void find (vector<vector<string>> &ans, vector<string> &curr, string word, string &begin, int i, unordered_map<string, int> &words) {
        curr.push_back(word);
        if (i==0) {
            if (word == begin) { //this check is not compulsory since we are sure that only beginWord will have distance 0
                vector<string> temp = curr;
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            curr.pop_back();
            return;
        }
        for (int j=0; j<word.size(); j++) {
            string t = word;
            for (char ch='a'; ch<='z'; ch++) {
                t[j] = ch;
                if (words.find(t)!=words.end() && words[t]==i-1) {
                    find(ans, curr, t, begin, i-1, words);
                }
            }
        }
        curr.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//variables and containers needed
        vector<vector<string>> ans;
        vector<string> curr;
        queue<string> q;
        unordered_map<string, int> words;
        bool found = false;

        for (string s: wordList) {
            if (s == endWord) found = true;
            words[s] = INT_MAX;
        }
        if (!found) return {}; //endWord doesn't exist in wordList => no solution
        found = false;

        q.push(beginWord);
        words[beginWord] = 0;  //beginWord is at distance 0

//usual dfs approach
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string s = q.front();
                q.pop();
                for (int i=0; i<s.size(); i++) {
                    string t = s;
                    for (char ch='a'; ch<='z'; ch++) {
                        t[i] = ch;
                        if (words.find(t)!=words.end() && words[t]==INT_MAX) {
                            words[t] = words[s] + 1; //current word is at +1 distance from last
                            q.push(t);
                        }
                    }
                }
            }
        }

        find(ans, curr, endWord, beginWord, words[endWord], words);
        return ans;

    }
};