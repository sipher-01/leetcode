#include <bits/stdc++.h>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));
        diff[0][0]=0;
        int r[4] = {1,0,-1,0};
        int c[4] = {0,1,0,-1};
        while(!pq.empty()){
            int edgeDiff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1){
                return edgeDiff;
            }
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int effort = max(abs(heights[nr][nc]-heights[row][col]),edgeDiff);
                    if(effort<diff[nr][nc]){
                        diff[nr][nc] = effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};