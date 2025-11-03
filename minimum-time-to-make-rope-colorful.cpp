class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();

        int p1=0,p2=1;
        int ans = 0;
        while(p2 < n && p1 < n){
            if(colors[p1]!=colors[p2]){
               if(p1<p2){
                    p1 = p2;
                    p2++; 
               }
               else{
                    p2 = p1;
                    p1++;
               }
            }
            else{
                if(neededTime[p1]<neededTime[p2]){
                    ans += neededTime[p1];
                    p1 = p1<p2? p2+1:p1+1;
                }
                else{
                    ans += neededTime[p2];
                    p2 = p1<p2?p2+1:p1+1;
                }
            }
        }

        return ans;
    }
};