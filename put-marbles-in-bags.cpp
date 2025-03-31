class Solution {
public:
    using ll = long long;
    long long putMarbles(vector<int>& weights, int k) {
        ll n = weights.size();
        if(n==k || k==1)return 0;
        priority_queue<ll> maxHeap;  // Max-heap for largest k-1 elements
        priority_queue<ll, vector<ll>, greater<ll>> minHeap; // Min-heap for smallest k-1 elements

        for (int i = 1; i < n; i++) {
            ll sum = weights[i] + weights[i - 1];
            maxHeap.push(sum);
            minHeap.push(sum);
        }

        ll minSum = 0, maxSum = 0;
        
        for (int i = 0; i < k - 1; i++) {
            minSum += minHeap.top(); minHeap.pop(); 
            maxSum += maxHeap.top(); maxHeap.pop();
        }

        return maxSum - minSum;
    }   
};