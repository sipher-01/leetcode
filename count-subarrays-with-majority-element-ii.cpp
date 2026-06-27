class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>cs;
        long long res = 0;
        long long validPoints = 0;
        long long csum = 0;
        cs[0]=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                validPoints += cs[csum];
                csum += 1;
            }
            else{
                csum -= 1;
                validPoints -= cs[csum]; 
            }

            res += validPoints;
            cs[csum]++;
        }

        return res;
    }
};