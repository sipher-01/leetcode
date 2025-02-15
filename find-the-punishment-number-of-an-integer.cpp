class Solution {
public:
    bool solve(int i, string s, int sum, int target){
        if(sum>target)return false;
        if(i==s.length())return sum==target;

        for(int j=i+1; j<=s.length();j++){
            string temp = s.substr(i,j-i);
            int a = stoi(temp) ;
            if(solve(j,s,sum+a,target))return true;
        }
        return false;
    }
    bool is_valid(int num, string s){
        return solve(0,s,0, num);
    }
    int punishmentNumber(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++){
            int sq = i*i;
            if(is_valid(i,to_string(sq))){
                ans += (sq);
            }
        }
        return ans;
    }
};