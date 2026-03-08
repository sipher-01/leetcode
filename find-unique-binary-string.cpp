class Solution {
public:
    bool solve(int i, int n, set<string>&st, string temp, string &s){
        if(i>=n){
            if(st.count(temp)==0){
                s = temp;
                return true;
            }
            return false;
        }

        if (solve(i+1,n,st,temp+'0',s))return true;
        if (solve(i+1,n,st,temp+'1',s))return true;
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st(nums.begin(),nums.end());
        int n = nums[0].size();
        if(st.size() == pow(2,n))return "";
        string s = "";
        solve(0,n,st,"",s);
        return s;
    }
};