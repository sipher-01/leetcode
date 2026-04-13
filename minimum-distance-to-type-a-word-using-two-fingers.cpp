class Solution {
    int dp[301][27][27];
public:
    int dist(int a, int b){
        int x1 = a/6,y1=a%6;
        int x2 = b/6,y2=b%6;
        return abs(x1-x2) + abs(y1-y2);
    }
    int solve(string& word, int i, int f1, int f2){
        if(i>=word.length()){
            return 0;
        }
        int cur = word[i] - 'A';
        int res = INT_MAX;
        if(dp[i][f1][f2]!=-1)return dp[i][f1][f2];
        if(f1==26 && f2==26){
            return dp[i][f1][f2] = solve(word,i+1,cur,f2);
        }
        if(f2==26){
            int move2 = solve(word,i+1,f1,cur);
            int move1 = dist(cur,f1)+solve(word,i+1,cur,f2);
            res = min(move1, move2);
            return dp[i][f1][f2] = res;
        }
        int move2 = dist(cur,f2) + solve(word,i+1,f1,cur);
        int move1 = dist(cur,f1) + solve(word,i+1,cur,f2);
        res = min(move1, move2);
        return dp[i][f1][f2] = res;
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return solve(word,0,26,26);
    }
};