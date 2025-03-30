class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        int start = 0;
        vector<int>ans;
        while(start<n){
            int end = mp[s[start]];
            int nextEle = start+1;
            while(nextEle < end){
                char c = s[nextEle];
                end = max(end,mp[c]);
                nextEle++;
            }
            ans.push_back(end-start+1);
            start = end+1;
        }
        return ans;
    }
};