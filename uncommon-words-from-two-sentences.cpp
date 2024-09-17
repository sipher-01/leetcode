class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>str1;
        vector<string>str2;
        vector<string>ans;
        int  len1 = s1.length();
        int  len2 = s2.length();
        int start = 0;
        for(int i=0; i<=len1; i++){
            if(s1[i]==' ' || i == len1){
                str1.push_back(s1.substr(start,i-start));
                if(i!=len1-1)start = i+1;
            }
        }
        start = 0;
        for(int i=0; i<=len2; i++){
            if(s2[i]==' ' || i == len2){
                str2.push_back(s2.substr(start,i-start));
                if(i!=len2-1)start = i+1;
            }
        }
        unordered_map<string,int>mp;
        for(auto it: str1){
            mp[it]++;
        }
        for(auto it: str2){
            mp[it]++;
        }
        for(auto it: mp){
            if(it.second == 1)ans.push_back(it.first);
        }

        return ans;
    }
};