class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        int N = restrictions.size();

        for(int i = 1; i<N; i++){
            int diff = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1],(restrictions[i-1][1] + diff));
        }

        for(int i = N-2; i>=0; i--){
            int diff = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],(restrictions[i+1][1] + diff));
        }
        int res = 0;
        for(int i=1; i<N; i++){
            int pos1 =  restrictions[i-1][0];
            int h1 = restrictions[i-1][1];

            int pos2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int pdiff = pos2 - pos1;
            int hdiff = abs(h2 - h1);

            int peak = max(h1,h2) + (pdiff - hdiff)/2;

            res = max(res,peak);
        }

        return res;
    }
};