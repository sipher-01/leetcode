class Solution {

public:
    void subset(int i, string &s,string temp, unordered_set<string>&st){
        if(i==s.length()){
            st.insert(temp);
            return;
        }
        subset(i+1,s,temp,st);
        subset(i+1,s,temp+s[i],st);
        return;
    }

    void permutation(int i,string &s,unordered_set<string>&st){
        if(i==s.length()){
            st.insert(s);
            return;
        }
        for(int j=i; j<s.length(); j++){
            swap(s[i],s[j]);
            permutation(i+1,s,st);
            swap(s[i],s[j]);
        }

    }
    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        subset(0,tiles,"",st);
        unordered_set<string>res;
        for(auto it: st){
            if(it.length()!=0){
               permutation(0,it,res);
            }
        }
        return res.size();
    }
};