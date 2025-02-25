#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        int evenCount = 1;
        int oddCount = 0;
        int ans = 0;
        for(auto &it: arr){
            sum += it;
            if(sum%2==0){
                ans = (ans + oddCount)% mod ;
                evenCount++;
            }
            else{
                ans = (ans+evenCount) % mod;
                oddCount++;
            }
        }

        return ans%mod;
    }
};