class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1){
            int ans = -1;
            unordered_map<int,int>mp;
            for(int i=0; i<n; i++){
                mp[nums[i]]++;
            }
            for(auto it: mp){
                if(it.second == 1){
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }
        else if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        int p1 = nums[0];
        int p2 = nums[n-1];

        for(int i=1; i<n-1; i++){
            if(p1 == nums[i]){
                p1 = -1;
            }
            if(p2 == nums[i]){
                p2 = -1;
            }
        }
        if((p1 == -1 && p2 == -1) || (p1==p2))return -1;
        if(p1 >= 0 && p2 >= 0) return max(p1,p2);
        if(p1==-1)return p2;
        if(p2==-1)return p1;
        return -1;
    }
};