class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it: supplies){
            mp[it]++;
        }
        int n = recipes.size();
        vector<bool>notMake(n,false);
        int cnt = n;
        while(cnt--){
            for(int i=0; i<n; i++){
                if(notMake[i])continue;
                bool flag=true;
                for(auto it: ingredients[i]){
                    if(mp.find(it)==mp.end()){
                        flag = false;
                    }
                }
                if(flag){
                    mp[recipes[i]]++;
                    ans.push_back(recipes[i]);
                    notMake[i] = true;
                }
            }
        }


        return ans;
    }
};