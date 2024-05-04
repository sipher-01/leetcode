class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int a;
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            pq.push(i);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        a=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>a){
            pq.pop();
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */