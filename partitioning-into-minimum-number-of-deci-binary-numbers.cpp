class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char &c: n){
            int num = c - '0';
            ans = max(ans,num);
        }
        return ans;
    }
};