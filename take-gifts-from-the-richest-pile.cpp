class Solution {
private: 
    long long sqr(long long x){
        long long l = 0, r = x;
        long long ans ;
        while(l<=r){
            long long mid = (r + (r-l))/2;
            if(mid * mid == x){
                ans = mid;
                break;
            }
            else if(mid*mid<x){
                ans = mid;
                l = mid +1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq;
        for(auto it: gifts){
            pq.push(it);
        }
        while(k--){
            long long top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        long long ans = 0;
        while(!pq.empty()){
            long long top = pq.top();
            pq.pop();
            ans += top;
        }
        return ans;
    }
};