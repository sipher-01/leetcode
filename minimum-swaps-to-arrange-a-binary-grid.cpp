class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zero(n,0);

        for(int i=0; i<n; i++){
            int j = n-1;
            int z = 0;
            while(j>=0 && grid[i][j]==0){
                z++;
                j--;
            }
            zero[i] = z;
        }
        int ops = 0;
        for(int i = 0; i < n; i++) {
            int needed = n - 1 - i;
            int j = i;

            while(j < n && zero[j] < needed) {
                j++;
            }

            if(j == n) return -1;

            while(j > i) {
                swap(zero[j], zero[j-1]);
                j--;
                ops++;
            }
        }

        return ops;
    }
};