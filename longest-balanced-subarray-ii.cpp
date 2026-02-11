struct node{
    int mn;
    int mx;
};
class SegmentTree{
    vector<node>st;
    vector<int>lazy;
public:
    SegmentTree(int n){
        st.assign(4*n,{0,0});
        lazy.assign(4*n,0);
    }
    void lazy_dealer(int i, int l, int r){
        if(lazy[i]==0)return;
        st[i].mn += lazy[i];
        st[i].mx += lazy[i];
        if(l!=r){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
        return;
    }
    void range_update(int i, int start, int end, int l ,int r, int val){
        lazy_dealer(i,l,r);
        if(r<start || l>end){
            return;
        }
        if(start<=l && r<=end){
            lazy[i] += val;
            lazy_dealer(i,l,r);
            return;
        }
        int mid = (l+r)/2;
        range_update(2*i+1,start,end,l,mid,val);
        range_update(2*i+2,start,end,mid+1,r,val);

        st[i].mn = min(st[2*i+1].mn,st[2*i+2].mn);
        st[i].mx = max(st[2*i+1].mx,st[2*i+2].mx);
    }
    int findzeroind(int i, int l, int r){
        lazy_dealer(i,l,r);
        if(st[i].mn>0 || st[i].mx<0){
            return -1;
        }
        if(l==r){
            return l;
        }
        int mid = (l+r)/2;
        int ind = findzeroind(2*i+1, l, mid);
        if(ind!=-1)return ind;
        return findzeroind(2*i+2, mid+1, r);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        vector<int>csum(n);
        SegmentTree st(n);
        unordered_map<int,int>mp;
        int ans = 0;

        for(int i=0; i<n; i++){
            int val = (nums[i]%2)?-1:1;
            int prev = -1;
            if(mp.count(nums[i])){
                prev = mp[nums[i]];
            }
            if(prev!=-1){
                st.range_update(0,0,prev,0,n-1,-val);
            }
            st.range_update(0,0,i,0,n-1,val);

            int j = st.findzeroind(0,0,n-1);
            if(j!=-1){
                ans = max(ans,i-j+1);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
