class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        set<char>s;
        int len =words.size();
        for(auto it: allowed){
            s.insert(it);
        }
        for(auto word: words){
            int flag =1;
           for(auto i: word){
                if(s.find(i)==s.end()){
                    flag=0;
                    break;
                }
           }
           cnt+=flag;
        }
        return cnt;
    }
};