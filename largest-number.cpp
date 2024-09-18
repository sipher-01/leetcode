class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b)->bool{
            string a1 = to_string(a);
            string b1 = to_string(b);
            if((a1+b1)>(b1+a1))return true;
            else return false;
        });
        if(nums[0]==0)return "0";
        string ans = "";
        for(int it: nums){
            ans += to_string(it);
        }
        return ans;
        
    }
};