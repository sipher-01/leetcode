class Solution {
    using ll = long long;
    int s_k;
    const ll inf = 1e18;
    map<tuple<int,int,int>,ll>dp;
public:
    ll solve(int i, int k, vector<int>&nums, int dist,int second){
        if(i>=nums.size()){
            return inf;
        }
        if(k==1){
            if((i-second)<=dist){
                return nums[i];
            }
            return inf;
        }
        auto key = make_tuple(i,k,second);
        if(dp.count(key))return dp[key];
        ll res = inf;
        if(k==s_k){
            second = i;
        }
        for(int j=i; j<=nums.size()-k; j++){
            ll cost = solve(j+1,k-1,nums,dist,second);
            if(cost==inf)continue;
            res = min(res, nums[i]+cost);
        }
        return dp[key] = res;
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = 0;
        ans += nums[0];
        // s_k = k-1;
        // dp.clear();
        // ans += solve(0,k,nums,dist,-1);
        // return ans;
        ll sum = 0;
        set<pair<ll,ll>>min_el;
        set<pair<ll,ll>>rem;
        ll res = inf;
        k--;
        int l = 1;
        ll i=1;
        while(i-dist<1){
            sum += nums[i];
            min_el.insert({nums[i],i});
            if(min_el.size()>k){
                auto it = *min_el.rbegin();
                rem.insert(it);
                sum -= it.first;
                min_el.erase(it);
            }
            i++;
        }
        while(i<nums.size()){
            sum += nums[i];
            min_el.insert({nums[i],i});
            if(min_el.size()>k){
                auto it = *min_el.rbegin();
                rem.insert(it);
                sum -= it.first;
                min_el.erase(it);
            }
            res = min(res,sum);
            pair<ll,ll> r = {(ll)nums[i - dist],i-dist};
            if(min_el.count(r)){
                min_el.erase(r);
                sum -= r.first;
                if(!rem.empty()){
                    auto it = *rem.begin();
                    min_el.insert(it);
                    sum += it.first;
                    rem.erase(it);
                }
            }
            else rem.erase(r);
            i++;
        }
        

        // for(int i=1; i<nums.size(); i++){
        //     if(i-dist>0){
        //         if(min_el.count({nums[l],l})){
        //             min_el.erase({nums[l],l});
        //             sum -= nums[l];
        //             if(!rem.empty()){
        //                 auto it = *rem.begin();
        //                 min_el.insert(it);
        //                 sum += it.first;
        //                 rem.erase(it);
        //             }
        //         }
        //         else rem.erase({nums[l],l});
        //     }
        //     sum += nums[i];
        //     min_el.insert({nums[i],i});
        //     if(min_el.size()>k){
        //         auto it = *min_el.rbegin();
        //         rem.insert(it);
        //         sum -= nums[it.first];
        //         min_el.erase(it);
        //     }
        //     res = min(res,sum);
        // }
        return ans + res;
    }
};