class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>temp(501,0);
        for(auto it: nums){
            temp[it]++;
        }
        for(int i=1; i<501; i++){
            if(temp[i]%2!=0)return false;
        }
        return true;
    }
};