class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>visi(26),num(26);

        for(auto c: s){
            num[c-'a']++;
        }

        string str;
        for(char &c: s){
            int i = c - 'a';
            if(!visi[i]){
                while(!str.empty() && str.back()>c){
                    int j = str.back() - 'a';
                    if(num[j]>0){
                        visi[j] = 0;
                        str.pop_back();
                    }
                    else{
                        break;
                    }
                }
                visi[i] = 1;
                str.push_back(c);
            }
            num[i] -= 1;
        }
        return str;
    }
};