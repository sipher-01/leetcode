class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> res(m,vector<char>(n,'.'));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[j][i] = box[i][j];
            }
        }
        for(auto &row: res){
            reverse(row.begin(),row.end());
        }

        for(int i=0; i<n; i++){
            int stone = m-1;
            for(int j=m-1; j>=0; j--){
                if(res[j][i]=='*'){
                    stone = j-1;
                    continue;
                }
                if(res[j][i]=='#'){
                    res[j][i] = '.';
                    res[stone][i] = '#';
                    stone--;
                }
            }
        }

        return res;
    }
};