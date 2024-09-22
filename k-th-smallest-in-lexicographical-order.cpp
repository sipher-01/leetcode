# include<bits/stdc++.h>
class Solution {
public:
    int getReq(long i, long j, long n){
        int steps = 0;
        while(i<=n){
            steps += min(n+1,j) - i;
            i *= 10;
            j *= 10; 
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long num = 1;
        for(int i=1; i<k;){
            int req = getReq(num,num+1,n);
            if(i+req <= k){
                i += req;
                num++;
            }
            else{
                i++;
                num *= 10;
            }
        }
        return num;
    }
};