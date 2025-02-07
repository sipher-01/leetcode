class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>color,ball;
        vector<int>ans;

        for(auto it: queries){
            int b = it[0], c = it[1];

            if(ball.find(b)!=ball.end()){
                int prevColor = ball[b];
                color[prevColor]--;
                if(color[prevColor]==0)color.erase(prevColor);
            }
            ball[b] = c;
            color[c]++;
            ans.push_back(color.size());
        }
        return ans;
    }
};