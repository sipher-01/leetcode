class Solution {
    const int mod = 1e9+7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{0,0}));
        dp[n-1][n-1].first = 0;
        dp[n-1][n-1].second = 1;

        //edge cases right column
        for(int i=n-2; i>=0; i--){
            if(board[i][n-1] == 'X'){
                dp[i][n-1].first = -1;
                dp[i][n-1].second = -1;
                break;
            }
            dp[i][n-1].first = dp[i+1][n-1].first + (board[i][n-1]-'0');
            dp[i][n-1].second = 1;
        }
        // edges cases bottom row
        for(int j=n-2; j>=0; j--){
            if(board[n-1][j] == 'X'){
                dp[n-1][j].first = -1;
                dp[n-1][j].second = -1;
                break;
            }
            dp[n-1][j].first = dp[n-1][j+1].first + (board[n-1][j]-'0');
            dp[n-1][j].second = 1;
        }

        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(board[i][j]=='X'){
                    dp[i][j].first = -1;
                    dp[i][j].second = -1; 
                    continue;
                }
                int num = board[i][j]=='E'? 0 : (board[i][j] - '0');
                //right
                int rightCost = dp[i][j+1].first;
                int rightPaths = dp[i][j+1].second;
                //down
                int downCost = dp[i+1][j].first;
                int downPaths = dp[i+1][j].second;
                //diag
                int diagCost = dp[i+1][j+1].first;
                int diagPaths = dp[i+1][j+1].second;

                if(rightCost > downCost && rightCost > diagCost){
                    dp[i][j].first = rightCost + num;
                    dp[i][j].second = rightPaths;
                }
                else if(downCost > rightCost && downCost > diagCost){
                    dp[i][j].first = downCost + num;
                    dp[i][j].second = downPaths;
                }
                else if(diagCost > rightCost && diagCost > downCost){
                    dp[i][j].first = diagCost + num;
                    dp[i][j].second = diagPaths;
                }
                else if(downCost == rightCost){
                    dp[i][j].first = rightCost + num;
                    dp[i][j].second = (rightPaths + downPaths)%mod;
                }
                
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<")  ";
            }
            cout<<"\n";
        }
        int f = dp[0][0].first;
        int s = dp[0][0].second;
        if(s==0)return {0,0};
        return {f,s};
    }
};