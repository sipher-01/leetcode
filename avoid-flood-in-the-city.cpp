class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            if(rains[i]==0){
                ans[i] = 1;
                continue;
            }
            if(mp.find(rains[i])!=mp.end()){
                bool flag = false;
                for(int j=mp[rains[i]]+1; j<=i-1; j++){
                    if (rains[j]==0){
                        ans[j]=rains[i];
                        rains[j] = -1;
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {return {};}
            }
            mp[rains[i]] = i;
        }
        return ans;
    }
};