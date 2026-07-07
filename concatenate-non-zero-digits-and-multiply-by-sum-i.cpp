class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        string s = "";
        long long sum = 0;
        while(n>0){
            int c = n%10;
            sum += c;
            n /= 10;
            if(c==0)continue;
            s += to_string(c);
        }
        reverse(s.begin(),s.end());
        return stoi(s)*sum;
    }
};