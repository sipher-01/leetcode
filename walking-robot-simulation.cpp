class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir =0;
        unordered_set<string>st;
        for(auto it : obstacles){
            st.insert(to_string(it[0])+','+to_string(it[1]));
        }
        int x=0, y=0;
        int ans=0;
        for(auto command : commands){
            if(command == -2){
                dir = (dir + 3)%4;
            }
            else if(command == -1){
                dir = (dir+1)%4;
            }
            for(int i =0; i<command; i++){
                int nx = x + direction[dir].first;
                int ny = y + direction[dir].second;
                if(st.find(to_string(nx)+','+to_string(ny)) == st.end()){
                    x = nx;
                    y = ny;
                    ans = max(ans,x*x+y*y);
                }
                else break;
            }
        }
        return ans;
    }
};