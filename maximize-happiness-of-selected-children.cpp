class Solution {
public:
using ll = long long;
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll n = happiness.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0; i<n; i++){
            if(!pq.empty() && pq.size()==k && pq.top() < happiness[i]){
                pq.pop();
                pq.push(happiness[i]);
            }
            if(pq.empty() || pq.size()<k) pq.push(happiness[i]);
        }
        ll diff = k-1;
        ll ans = 0;
        while(!pq.empty()){
            int num = pq.top();
            cout<<num<<endl;
            pq.pop();
            ans += (num - diff)>0 ? (num - diff) : 0;
            diff--;
        }
        return ans;
    }
};