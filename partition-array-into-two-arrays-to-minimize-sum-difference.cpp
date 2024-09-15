class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(),res=INT_MAX;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = N/2;
        vector<vector<int>>left(n+1),right(n+1);

        for(int mask = 0; mask<(1<<n); mask++){
            int sz = 0, l=0, r=0;
            for(int i =0; i<n; i++){
                if(mask&(1<<i)){
                    sz++;
                    l+=nums[i];
                    r+=nums[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        for(int sz = 0; sz<=n; sz++){
            sort(right[sz].begin(),right[sz].end());
        }
        for(int sz=1; sz<=n; sz++){
            for(auto &a: left[sz]){
                int b = (sum/2) - a, rsz =n - sz;
                auto &v = right[rsz];
                auto it = lower_bound(v.begin(),v.end(),b);
                if(it!=v.end())res = min(res,abs(sum-2*(a+(*it))));
                if(it!=v.begin()){
                    auto itr = it; itr--;
                    res = min(res,abs(sum-2*(a+(*itr))));
                }
            }
        }
        return res;
        //         for (int sz = 0; sz <= n; sz++) {
        //     for (int a : left[sz]) {
        //         int target = (sum / 2) - a;  // We want to find something close to this target in right[rsz]
        //         int rsz = n - sz;
        //         auto &v = right[rsz];

        //         // Binary search for closest value
        //         auto it = lower_bound(v.begin(), v.end(), target);

        //         if (it != v.end()) {
        //             res = min(res, abs(sum - 2 * (a + *it)));
        //         }
        //         if (it != v.begin()) {
        //             --it;
        //             res = min(res, abs(sum - 2 * (a + *it)));
        //         }
        //     }
        // }

        // return res;
    }
};