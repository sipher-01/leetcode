class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int prev=0,curr = 1;
        int n = height.size();
        vector<int>ans;
        while(curr<n){
            if(height[prev]>threshold){
                ans.push_back(curr);
            }
            curr++;
            prev++;
        }
        return ans;
    }
};