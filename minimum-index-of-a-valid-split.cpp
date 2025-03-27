class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        int x=-1,f=0;

        for(auto it: mp){
            if(it.second > f){
                x = it.first;
                f = it.second;
            }
        }
        int n = nums.size();
        int pos = -1;
        int f1 = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==x){
                f1++;
            }
            int f2 = f - f1;
            if(f1>(i+1-f1) && f2 > (n-1 - i - f2)){
                pos = i;
                break;
            }
        }
        return pos;
    }
};