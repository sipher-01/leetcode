class Solution {
public:
    using ll = long long;
    long long putMarbles(vector<int>& weights, int k) {
        ll n = weights.size();
        if(n==k || k==1)return 0;
        // priority_queue<int>pq;
        vector<ll>pq;
        for(int i=1; i<n; i++){
            pq.push_back(weights[i]+weights[i-1]);
        }
        sort(pq.begin(),pq.end());
        ll maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pq[i];                          // Smallest k-1 sums
            maxSum += pq[n - 2 - i];                  // Largest k-1 sums
        }

        return maxSum - minSum;
        // int maxSum = 0;
        // int l = k-1;
        // while(l--){
        //     int val = pq.top();
        //     pq.pop();
        //     maxSum += val;
        // }
        // while(pq.size()>k-1){
        //     pq.pop();
        // }
        // while(!pq.empty())
    }   
};