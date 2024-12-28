class Solution {
private:
    vector<int>ans;
    vector<int>subarr;
    int dp[20001][4];
public:
    int helper(int count, int k, int i){
        int n = subarr.size();
        if(count==0)return 0;
        if(i>=n)return INT_MIN;

        if(dp[i][count]!=-1)return dp[i][count];

        int take = subarr[i] + helper(count-1,k,i+k);
        int notTake = helper(count, k, i+1);

        return dp[i][count] = max(take,notTake);
    }

    void solve(int count, int k, int i){
        int n = subarr.size();
        if(count==0)return;
        if(i>=n)return;

        int take = subarr[i] + helper(count-1,k,i+k);
        int notTake = helper(count,k,i+1);

        if(take>=notTake){
            ans.push_back(i);
            solve(count-1,k,i+k);
        }
        else{
            solve(count,k,i+1);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int l=0, r=0;
        int sum = nums[0];
        while(r<nums.size()){
            sum += nums[r];
            if(r-l+1==k){
                subarr.push_back(sum);
                sum -= nums[l];
                l++;
            }
            r++;
        } 
        solve(3,k,0);
        return ans;
    }
};