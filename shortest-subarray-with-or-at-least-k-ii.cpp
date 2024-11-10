class Solution {
    int x=32;
    vector<int>bitFreq;
public:
Solution():bitFreq(x,0){};
    void update(int num, int val){
        for(int i=0; i<32; i++){
            if(num & (1<<i)){
                bitFreq[i] += val;
            }
        }
    }
    int get(){
        int val = 0;
        int pow = 1;
        for(int i=0; i<32; i++){
            if(bitFreq[i]>0){
                val |= pow;;
            }
            pow <<= 1;
        }
        return val;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        int n = nums.size();
        int track = 0;
        int ans = INT_MAX;
        while(r<n){
            update(nums[r],1);
            track |= nums[r];
            while(track>=k && l<=r){
                ans = min(ans,r-l+1);
                update(nums[l],-1);
                track = get();
                l++;
            }
            r++;
        }

        return ans==INT_MAX?-1:ans;
    }
};