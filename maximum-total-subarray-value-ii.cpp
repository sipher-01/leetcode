class SegmentTree{
vector<int>st;
bool isMin;

public:
    SegmentTree(vector<int>&nums, bool flag){
        int n = nums.size();
        st.resize(4*n);
        isMin = flag;
        buildSegmentTree(0,0,n-1,nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums){

        if(l == r){
            st[i] = nums[l];
            return ;
        }

        int mid = l + (r-l)/2;

        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);

        if(isMin){
            st[i] = min(st[2*i+1],st[2*i+2]);
        }
        else{
            st[i] = max(st[2*i+1],st[2*i+2]);
        }
    }
    int rangeQuery(int start, int end, int i, int l, int r){
        if(end<l || start>r){
            return isMin?INT_MAX:INT_MIN;
        }

        if(l>=start && r<=end){
            return st[i];
        }
        int mid = l + (r-l)/2;

        int a = rangeQuery(start,end,2*i+1,l,mid);
        int b = rangeQuery(start,end,2*i+2,mid+1,r);

        if(isMin){
            return min(a,b);
        }
        else{
            return max(a,b);
        }
    }

    int query(int l, int r, int n){
        return rangeQuery(l,r,0,0,n-1);
    }
};



class Solution {
using ll = long long;
public:

    ll getValue(int l, int r, SegmentTree& minSt, SegmentTree& maxSt, int n){
        int mn = minSt.query(l,r,n);
        int mx = maxSt.query(l,r,n);

        return (ll)mx - mn;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree minSt(nums,true);
        SegmentTree maxSt(nums,false);

        priority_queue<tuple<ll,int,int>>pq;

        for(int l=0; l<n; l++){

            ll value = getValue(l, n-1,minSt, maxSt, n);

            pq.push({value,l,n-1});
        }

        ll res = 0;

        while(k--){
            auto [val,l,r] = pq.top();
            res += val;
            pq.pop();
            ll nextBestValue = getValue(l,r-1,minSt,maxSt, n);
            pq.push({nextBestValue,l,r-1});
        }

        return res;
    }
};