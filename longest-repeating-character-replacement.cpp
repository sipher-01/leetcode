class Solution {
public:
    int characterReplacement(string s, int k) {
            unordered_map<char,int>mp;
    int start = 0, ans = 0, n = s.size(), maxFreq=0;
    for(int end=0; end<n; end++){
        mp[s[end]]++;
        maxFreq = max(maxFreq, mp[s[end]]);
        while(end-start+1-maxFreq > k){
            mp[s[start]]--;
            start++;
        }
        ans = max(ans, end-start+1);
    }
    return ans;
    }
};