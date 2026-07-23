class SegmentTree{
int n;
vector<int>arr;
vector<int>st;

    void build(int i, int s, int e){
        if(s==e){
            st[i] = arr[s];
            return ;
        }
        int mid = (s+e)>>1;
        build(i<<1,s,mid);
        build(i<<1|1,mid+1,e);

        st[i] = max(st[i<<1],st[i<<1|1]);
    }

    int _query(int i, int s, int e, int l, int r){
        // if(s>r || e < l){
        //     return 0;
        // }
        if(l<=s && e<=r){
            return st[i];
        }
        int mid = (s+e)>>1;
        int res = 0;
        if (l <= mid) {
            res = max(res, _query(i << 1, s, mid, l, r));
        }
        if (r > mid) {
            res = max(res, _query(i << 1 | 1, mid + 1, e, l, r));
        }

        return res;
    }
public:
    SegmentTree(const vector<int>& arr):arr(arr){
        n = arr.size();
        st.resize(n<<2,0);
        build(1,0,n-1);
    }
    int rmq(int l, int r){
        if(l>r){
            return 0;
        }
        return _query(1,0,n-1,l,r);
    }
};


class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int>zero,left,right;
        int n = s.length();
        int ones = count(s.begin(),s.end(),'1');

        int i=0;
        while(i<n){
            int start = i;
            while(i<n && s[i]==s[start])i++;
            if(s[start]=='0'){
                zero.push_back(i-start);
                right.push_back(i-1);
                left.push_back(start);
            }
        }
        int m = zero.size();
        if(m<=1)return vector<int>(queries.size(), ones);
        vector<int>pairSum;
        for(int i=0; i<m-1; i++){
            pairSum.push_back(zero[i]+zero[i+1]);
        }

        SegmentTree st(pairSum);
        vector<int>res;
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int i = lower_bound(right.begin(),right.end(),l)-right.begin();
            int j = upper_bound(left.begin(),left.end(),r)-left.begin() - 1;
            if(i>m-1 || j<0 || i>=j){
                res.push_back(ones);
                continue;
            }
            int start_zero = right[i] - max(l,left[i]) + 1;
            int end_zero = min(r,right[j]) - left[j] + 1;

            if(i+1 == j){
                res.push_back(start_zero + end_zero + ones);
                continue;
            }
            int val1 = start_zero + zero[i+1];
            int val2 = zero[j-1] + end_zero;
            int val3 = st.rmq(i+1,j-2);
            int bestGain = max({val1,val2,val3});
            res.push_back(ones+bestGain);
        }

        return res;
    }
};