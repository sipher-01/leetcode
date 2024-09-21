class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int num = 1;
        vector<int>ans;
        for(int i=0; i<n; i++){
            ans.push_back(num);
            if(num*10<=n)num = num*10;
            else{
                if(num+1<=n && num%10!=9)num = num+1;
                else{
                    while((num/10)%10 == 9)num /= 10;
                    num = num/10 + 1;
                }
            }
        }
        return ans;
    }
};