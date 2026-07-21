class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> zeroBlocks;
        int i = 0;
        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start]) {
                ++i;
            }

            if (s[start] == '0') {
                zeroBlocks.push_back(i - start);
            }
        }


        int ans = 0;

        auto solve = [&](){
            int one = 0;
            for(int i=0; i<n; i++){
                if(s[i]=='1'){
                    one++;
                }
            }

            return one;
        };

        int ones = solve();
        int l = zeroBlocks.size();

        if(l<2)return ones;

        for(int i=0; i<l-1; i++){
            int sum = zeroBlocks[i] + zeroBlocks[i+1];
            ans = max(ans,sum);
        }

        ans += ones;

        return ans;

    }
};