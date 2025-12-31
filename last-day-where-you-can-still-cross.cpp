
class Solution {
public:
    int totalRows, totalCols;

    bool canCrossOnDay(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(totalRows, vector<int>(totalCols, 0));

        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> visi(totalRows, vector<bool>(totalCols, false));

        for (int col = 0; col < totalCols; col++) {
            if (grid[0][col] == 0) {
                q.push({0, col});
                visi[0][col] = true;
            }
        }
        int r[4] = {-1,0,1,0};
        int c[4] = {0,1,0,-1};
        if(q.empty())return false;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int oldr = it.first;
            int oldc = it.second;
            if(oldr==totalRows-1)return true;
            for(int i=0; i<4; i++){
                int nr = oldr + r[i];
                int nc = oldc + c[i];
                if(nr<totalRows && nr>=0 && nc<totalCols && nc>=0 && grid[nr][nc]!=1 && !visi[nr][nc]){
                    q.push({nr,nc});
                    visi[nr][nc]=1;
                }
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        totalRows = row;
        totalCols = col;

        int left = 1;
        int right = cells.size();
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCrossOnDay(mid, cells)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};