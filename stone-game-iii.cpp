// class Solution {
// int n;
// // vector<vector<vector<int>>>dp;
// unordered_map<string,int>dp;
// public:
//     int solve(int i, int a, bool turn, vector<int>&values){
//         if(i >= n){
//             if(a>0)return a;
//             else if(a==0)return 0;
//             else return -a;
//         }
//         // int res = 0;
//         string key = to_string(i) + "#" + to_string(a) + "#" + (turn?"1":"0");
//         if(dp.count(key)>0)return dp[key]; 
//         // if(dp[i][])
//         if(turn){
//             int w1=-10,w2=-10,w3=-10;
//             w1 = solve(i+1, a + values[i], !turn, values);
//             if(i+1<n) w2 = solve(i+2, a + values[i] + values[i+1], !turn, values);
//             if(i+1<n && i+2<n) w3 = solve(i+3, a + values[i] + values[i+1] + values[i+2], !turn, values);
//             if(w1>0 || w2>0 ||w3>0)return dp[key] = a;
//             else if(w1==0 || w2==0 || w3==0)return dp[key] = 0;
//             return dp[key] = a;
//         }
//         else{
//             int w1=-10,w2=-10,w3=-10;
//             w1 = solve(i+1, a - values[i], !turn, values);
//             if(i+1<n) w2 = solve(i+2, a - values[i] - values[i+1], !turn, values);
//             if(i+1<n && i+2<n) w3 = solve(i+3, a - values[i] - values[i+1] - values[i+2], !turn, values);
//             if(w1<0 || w2<0 ||w3<0)return dp[key] = a;
//             else if(w1==0 || w2==0 || w3==0)return dp[key] =0;
//             return dp[key] = a;
//         }
//     }
//     string stoneGameIII(vector<int>& stoneValue) {
//         n = stoneValue.size();
//         int res = solve(0, 0, true, stoneValue);
//         // dp.resize(n+1,vector<vector<vector<int>>>(n+1,));
//         if(res>0)return "Alice";
//         else if(res==0)return "Tie";
//         return "Bob";
//     }
// };

class Solution {
    int n;
    vector<int> memo;

    int solve(int i, const vector<int>& values) {
        if (i >= n) return 0;
        if (memo[i] != -1e9) return memo[i];

        int res = -1e9;
        int sum = 0;
        
        // Try taking 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < n; ++k) {
            sum += values[i + k];
            // Current player takes 'sum', and subtracts whatever the opponent 
            // can optimally achieve from the remaining index (i + k + 1)
            res = max(res, sum - solve(i + k + 1, values));
        }

        return memo[i] = res;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.assign(n, -1e9);
        
        int res = solve(0, stoneValue);
        
        if (res > 0) return "Alice";
        else if (res == 0) return "Tie";
        return "Bob";
    }
};