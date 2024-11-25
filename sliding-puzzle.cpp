class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }
        string target = "123450";
        unordered_map<int,vector<int>>mp;
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {3,1,5};
        mp[5] = {2,4};
        queue<string>q;
        q.push(start);
        unordered_set<string>visi;
        visi.insert(start);
        int level = 0; 
        while(!q.empty()){
            int n = q.size();

            while(n--){
                string phase = q.front();
                q.pop();
                if(phase == target)return level;
                int indZero = phase.find('0');
                for(auto ind: mp[indZero]){
                    string newPhase = phase;
                    swap(newPhase[indZero],newPhase[ind]);
                    if(visi.find(newPhase) == visi.end()){
                        visi.insert(newPhase);
                        q.push(newPhase);
                    }
                }
            }
            level++;
        }
    return -1;
    }
};