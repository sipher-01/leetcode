class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        // for(int i=0; i<n; i++){
        //     int j = i+1;
        //     while(j<n){
        //         if(abs(ans[i]-ans[j])<=limit && ans[i]>ans[j]){
        //             swap(ans[i],ans[j]);
        //             j=i+1;
        //             continue;
        //         }
        //         j++;
        //     }
        // }

    //grouping
    unordered_map<int,queue<int>>group;
    unordered_map<int,int>member;
    int g=0;
    group[g].push(ans[0]);
    member[ans[0]] = g;
        for(int i=1; i<n; i++){
            if(abs(ans[i]-ans[i-1])<=limit){
                group[g].push(ans[i]);
                member[ans[i]] = g;
            }
            else{
                g++;
                group[g].push(ans[i]);
                member[ans[i]] = g;
            }
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            auto ind = member[nums[i]];
            res[i] = group[ind].front();
            group[ind].pop();
        }
        return res;
    }
};