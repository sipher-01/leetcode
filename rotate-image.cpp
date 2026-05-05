class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto transpose = [&](){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(j<i){
                        int a = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = a;
                    }
                }
            }
        };

        auto reversal = [&](){
            for(int i=0; i<n; i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        };
        transpose();
        reversal();
    }
};