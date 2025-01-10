class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        int arr[26] = {0};
        for(string s: words2){
            int temp[26] = {0};
            for(char c: s){
                temp[c-'a']++;
                arr[c-'a'] = max(arr[c-'a'],temp[c-'a']);
            }
        }

        for(string s: words1){
            int temp[26]={0};
            bool flag = false;
            for(char c: s){
                temp[c-'a']++;
            }
            for(int i=0; i<26; i++){
                if(arr[i]>temp[i]){
                    flag = false;
                    break;
                }
                flag = true;
            }
            if(flag)ans.push_back(s);
        }
        return ans;
    }
};