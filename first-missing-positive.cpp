class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        int i=1;
        while(true){
            if(mp.find(i)!=mp.end()){
                i++;
            }
            else break;
        }
        return i;
    }
};