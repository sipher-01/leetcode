class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        for(char &c: word){
            freq[c]++;
        }

        vector<pair<char,int>>a(freq.begin(),freq.end());
        sort(a.begin(),a.end(),[&](const auto& a, const auto& b){
            return a.second>b.second;
        });

        int cnt = 1;
        int ans = 0;
        int val = 1;
        for(auto it: a){
            if(cnt>8){
                val = 2;
            }
            if(cnt>16){
                val = 3;
            }
            if(cnt>24){
                val = 4;
            }
            int times = it.second;
            ans += (val*times);
            // cout<<it.first<<" : "<<it.second<<"  cnt : "<<cnt<<"  val : "<<val<<" ans : "<<ans<<endl;
            cnt++;
        }

        return ans;
    }
};