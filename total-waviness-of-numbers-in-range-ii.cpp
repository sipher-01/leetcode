class Solution {
    using ll = long long;
    string s;
    ll n;
    ll dp1[16][10][10];
    ll dp2[16][10][10];
public:

    pair<ll,ll> solve(ll cur, ll pre, ll prepre, bool isLimitNumber, bool isLeadingZero){
        if(cur==n){
            return {1,0};
        }
        ll limit = isLimitNumber ? s[cur]-'0': 9;

        ll totalNumbers = 0;
        ll totalWaves = 0;

        if(!isLimitNumber && !isLeadingZero && pre>=0 && prepre>=0){
            if(dp1[cur][pre][prepre]!=-1 && dp2[cur][pre][prepre]!=-1){
                return {dp1[cur][pre][prepre],dp2[cur][pre][prepre]};
            }
        }

        for(int digit=0; digit<=limit; digit++){
            bool newIsLeadingZero = isLeadingZero && (digit==0);
            ll newPrePre = newIsLeadingZero?-1:pre;
            ll newPre = newIsLeadingZero?-1:digit;
            auto [numbers, waves] = solve(cur+1,newPre, newPrePre,
            isLimitNumber && (digit==limit), newIsLeadingZero);

            if(!newIsLeadingZero && pre>=0 && prepre>=0){
                bool peak   = (pre > digit) && (pre > prepre);  // ← fix: pre > prepre
                bool valley = (pre < digit) && (pre < prepre);  // ← fix: pre < prepre
                if(peak || valley){
                    totalWaves += numbers;  // each future number has this wave point
                }
            }
            totalNumbers += numbers;
            totalWaves += waves;
        }

        if(!isLimitNumber && !isLeadingZero && pre>=0 && prepre>=0){
            dp1[cur][pre][prepre] = totalNumbers;
            dp2[cur][pre][prepre] = totalWaves;
        }

        return {totalNumbers,totalWaves};
    }

    ll func(ll num){
        if(num<100){
            return 0;
        }
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        s = to_string(num);
        n = s.length();
        auto [totalNumber,totalWaves] = solve(0,-1,-1,true,true);

        return totalWaves;
    }
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1-1);
    }
};