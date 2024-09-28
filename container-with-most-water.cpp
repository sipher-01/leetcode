class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans= 0;
        while(i<j){
            int w = j-i;
            int h;
            if(height[i]>height[j]){
                h=height[j];
                j--;
            }
            else{
                h = height[i];
                i++;
            }
                ans = max(ans,w*h);
            
        }
        return ans;

    }
};