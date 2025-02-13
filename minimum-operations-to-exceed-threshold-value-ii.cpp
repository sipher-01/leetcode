#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto it: nums){
            pq.push(it);
        }
        ll cnt = 0;
        while(pq.size() > 1 && pq.top() < k){
            ll x = pq.top();
            pq.pop();
            // if(x>=k)break;
            ll y = pq.top();
            pq.pop();
            ll op = x*2 + y;
            cnt++;
            pq.push(op);
        }
        return cnt;
    }
};