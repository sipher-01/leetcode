    using ll = long long;
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        multiset<pair<int,int>>top,rest;
        ll  sum = 0;
        vector<ll>ans;
        auto balance = [&](){
            while((int)top.size()<x && !rest.empty()){
                auto it = prev(rest.end());
                top.insert(*it);
                sum += 1LL * it->first * it->second;
                rest.erase(it);
            }

            // while((int)top.size()>x){
            //     auto it = top.begin();
            //     sum -= 1LL * it->first * it->second;
            //     rest.insert(*it);
            //     top.erase(it);
            // }

            while(!top.empty() && !rest.empty() && *prev(rest.end()) > *top.begin()){
                auto it1 = prev(rest.end());
                auto it2 = top.begin();
                sum += 1LL * it1->first * it1->second - 1LL * it2->first * it2->second;
                rest.insert(*it2);
                top.insert(*it1);
                rest.erase(it1);
                top.erase(it2);
            }
        };

        auto add = [&](int num){
            pair<int,int> old = {mp[num],num};
            if(top.find(old)!=top.end()){
                top.erase(top.find(old));
                sum -= (1LL * old.first * old.second);
            }
            else if(rest.find(old)!=rest.end()){
                rest.erase(rest.find(old));
            }
            mp[num]++;
            rest.insert({mp[num], num});
            balance();
        };
        auto remove = [&](int num){
            pair<int,int> old = {mp[num],num};
            if(top.find(old)!=top.end()){
                top.erase(top.find(old));
                sum -= (1LL * old.first * old.second);
            }
            else{
                rest.erase(rest.find(old));
            }
            mp[num]--;
            if(mp[num]>0){
                rest.insert({mp[num],num});
            }
            else 
                mp.erase(num);
            balance();
        };

        for(int i=0; i<k; i++){
            add(nums[i]);
        } 
        ans.push_back(sum);
        for(int i=k; i<n; i++){
            remove(nums[i-k]);
            add(nums[i]);
            ans.push_back(sum);
        }
        return ans;
    }
};