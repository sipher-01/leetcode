class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        
        int l = 1;
        int r = 1e5;
        using ll = long long;
        auto check = [&](int mid)->bool{
            ll op = 0;
            for(int i=0; i<n; i++){
                ll add_on = nums[i]%mid?1:0;
                op += (nums[i]/mid + add_on);
                if(op>(1LL*mid*mid))return false;
            }
            return op<=(1LL*mid*mid);
        };
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid)){
                ans = mid;
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};