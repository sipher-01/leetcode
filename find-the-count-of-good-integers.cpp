class Solution {
public:
    long long fact(int a){
        if(a==0||a==1)return 1;
        return a*fact(a-1);
    }
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>st;

        int m = (n+1)/2;
        int start = pow(10,m-1);
        int end = pow(10,m)-1;

        for(int num=start; num<=end; num++){
            string left = to_string(num);
            string full = "";

            if(n%2==0){
                string right = left;
                reverse(right.begin(),right.end());
                full = left + right;
            }
            else{
                string right = left.substr(0,m -1);
                reverse(right.begin(),right.end());
                full = left + right;
            }

            long long number = stoll(full);
            if(number%k!=0)continue;
            sort(full.begin(),full.end());
            st.insert(full);
        }
        vector<long long>fact(11,1);
        for(int i=1; i<11; i++){
            fact[i] = fact[i-1]*i;
        }
        long long ans = 0;
        for(const string &s: st){
            vector<int>mp(10,0);
            for(const char &c: s){
                mp[c-'0']++;
            }
            int total = s.length();
            int nonZero = s.length() - mp[0];
            long long perm = nonZero * fact[total-1];
            for(int i=0; i<10; i++){
                perm /= fact[mp[i]];
            }
            ans += perm;
        }

        return ans;
    }
};