class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0 ;i <nums.size(); i++){
            pq.push({nums[i],i});
        }
        int n = nums.size();
        vector<bool>visi(n,false);
        long long score = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int i = it.second;
            int p = it.first;
            pq.pop();
            if(!visi[i]){
                score += p;
                if(i+1<n)visi[i+1] = true;
                if(i-1>=0) visi[i-1]=true;
            }
        }

        return score;
    }
};