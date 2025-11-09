class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        
        while(true){
            if(num1>=num2){
                if( num2==0)break;
                ans+= num1/num2;
                num1 = num1%num2;
            }
            else{
                if(num1==0 )break;
                ans += num2/num1;
                num2 = num2%num1;
            }
        }
        return ans;
    }
};