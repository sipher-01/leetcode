class Solution {
public:
    bool dfs(int ind,  vector<vector<int>>&a, int n, vector<int>& visi){
        if(visi[ind]==1)return true;
        if (visi[ind] == 2) return false;
        visi[ind]=1;
        for(auto it: a[ind]){
            if(visi[it]!= 2){
                if(dfs(it,a,n,visi))return true;
            }
        }
        visi[ind]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>a(numCourses);
        //creating a 2d vector to use dfs on it with first element as index and second element as value
        for(int i=0; i<prerequisites.size(); ++i){
            a[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // now do dfs on all courses to see if we can do it
        vector<int>visi(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(visi[i]==0){
                // detecting cycle in a
                if (dfs(i,a,numCourses,visi)) return false;
            }
        }
        return true;
    }
};