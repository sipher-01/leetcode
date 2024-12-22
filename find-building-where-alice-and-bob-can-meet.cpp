class Solution {
public:
    void buildSegmentTree(vector<int>&segTree, vector<int>& heights, int l, int r,
    int ind){
        if(l == r){
            segTree[ind] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(segTree,heights,l,mid,2*ind);
        buildSegmentTree(segTree,heights,mid+1,r,2*ind+1);

        segTree[ind] = heights[segTree[2*ind]] >= heights[segTree[2*ind+1]]?
        segTree[2*ind]:segTree[2*ind+1];
    }

    int rangeMaxQuery(vector<int>&segTree,vector<int>& heights, int qs, int qe,
     int s, int e, int ind){
        if(s>=qs && e<=qe){
            return segTree[ind];
        }
        if(s>qe || e<qs){
            return INT_MIN;
        }
        int mid = s + (e-s)/2;
        int left = rangeMaxQuery(segTree,heights,qs,qe,s,mid,2*ind);
        int right = rangeMaxQuery(segTree,heights,qs,qe,mid+1,e,2*ind+1);
        if(left == INT_MIN)return right;
        if(right == INT_MIN)return left;

        return heights[left]>=heights[right]?left:right;

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int>segTree(4*n+1);
        int ind = 1;

        buildSegmentTree(segTree,heights,0,n-1,ind);

        vector<int>res;
        for(auto query: queries){
            int alice = min(query[0],query[1]);
            int bob = max(query[0],query[1]);
            if(alice == bob || heights[alice]<heights[bob]){
                res.push_back(bob);
                continue;
            }
            int l = bob;
            int r = n-1;
            int ans = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                int rmq = rangeMaxQuery(segTree,heights,l,mid,0,n-1,ind);
                if(heights[rmq]>heights[alice]){
                    r = mid - 1;
                    ans = min(ans,rmq);
                }
                else{
                    l = mid+1;
                }
            }
            if(ans == INT_MAX) res.push_back(-1);
            else res.push_back(ans);
        }
        return res;
    }
};