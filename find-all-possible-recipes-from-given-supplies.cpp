class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it: supplies){
            mp[it]++;
        }
        int n = recipes.size();
        unordered_map<string,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: ingredients[i]){
                if(mp.find(it)==mp.end()){
                    adj[it].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            ans.push_back(recipes[ind]);
            for(auto it: adj[recipes[ind]]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        // vector<bool>notMake(n,false);
        // int cnt = n;
        // while(cnt--){
        //     for(int i=0; i<n; i++){
        //         if(notMake[i])continue;
        //         bool flag=true;
        //         for(auto it: ingredients[i]){
        //             if(mp.find(it)==mp.end()){
        //                 flag = false;
        //             }
        //         }
        //         if(flag){
        //             mp[recipes[i]]++;
        //             ans.push_back(recipes[i]);
        //             notMake[i] = true;
        //         }
        //     }
        // }


        return ans;
    }
};