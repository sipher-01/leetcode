class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num: nums){
            int cnt = 0;
            int sum = 0;
            for(int i=1; i*i<=num; i++){
                if(num%i==0){
                    sum += i;
                    sum += num/i;
                    cnt += (i==num/i)?1:2;
                }
            }
            if(cnt==4){
                ans += sum;
            }
        }
        return ans;
    }
};