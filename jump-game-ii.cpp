#include<bits/stdc++.h>
class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    if(n==1)return 0;
    int totalJumps = 0;
    int destination = n-1;
    int coverage = 0, lastIndex = 0;
    for(int i=0; i<n-1; i++){
        if(i+nums[i]>coverage)coverage = i+nums[i];
        if(i==lastIndex){
            lastIndex = coverage;
            totalJumps++;
        }
    }
    return totalJumps;
    }
};