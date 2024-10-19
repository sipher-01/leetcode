class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
     unordered_map<string,int>freq;
     for(auto word: words){
        freq[word]++;
     }
     int n = s.size();  
     int wordSize = words.size();
     int len = words[0].length();
     vector<int>ans;
     for(int i=0; i<len; i++){
        int start = i, count = 0;
        unordered_map<string,int>mp;
        for(int j=i; j<=n-len; j+=len){
            string temp = s.substr(j,len);
            if(freq.find(temp)!=freq.end()){
                mp[temp]++;
                count++;
                while(mp[temp]>freq[temp]){
                    string left_word = s.substr(start,len);
                    mp[left_word]--;
                    count--;
                    start += len;
                }
                if(count==wordSize){
                    ans.push_back(start);
                }
            }
            else{
                mp.clear();
                count = 0;
                start = j + len;
            }
        }
     }
     return ans;
    }
};