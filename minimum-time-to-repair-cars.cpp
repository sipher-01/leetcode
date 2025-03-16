#define ll long long
#include <bits/stdc++.h>
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = 0;
        ll l = 1;
        ll r = (ll)(*max_element(ranks.begin(),ranks.end()))*cars*cars;

        while(l<=r){
            ll mid = l + (r-l)/2;
            if(check(ranks,mid,cars)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }

    bool check(vector<int>&ranks,ll mid, int cars){
        ll cnt = 0;
        for(int i=0; i<ranks.size(); i++){
            cnt += sqrt(mid/ranks[i]);
        }
        return cnt>=cars;
    }
};