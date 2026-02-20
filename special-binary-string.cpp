class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>sp;
        int start = 0;
        int sum = 0;
        for(int i=0; i<s.length(); i++){
            sum += s[i]=='1'?1:-1;
            if(sum==0){
                string t = s.substr(start+1,i-start-1);
                sp.push_back('1'+makeLargestSpecial(t)+'0');
                start = i+1;
            }
        }
        sort(sp.begin(),end(sp),greater<string>());

        string res = "";

        for(auto c: sp){
            res += c;
        }
        return res;
    }
};