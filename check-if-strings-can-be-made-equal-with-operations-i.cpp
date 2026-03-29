class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int>t1,t2;

        for(int i=0; i<s1.length(); i++){
            if(i%2==0){
                t1[s1[i]]++;
            }
            else{
                t2[s1[i]]++;
            }
        }

        for(int i=0; i<s1.length(); i++){
            if(i%2==0){
                if(t1.count(s2[i])==0){
                    return false;
                }
                else{
                    t1[s2[i]]--;
                }
            }
            if(i%2==1){
                if(t2.count(s2[i])==0){
                    return false;
                }
                else{
                    t2[s2[i]]--;
                }
            }
        }

        for(auto it: t1){
            if(it.second>0)return false;
        }
        for(auto it: t2){
            if(it.second>0)return false;
        }

        return true;
    }
};