class Solution {
public:
    bool isPossible(int n, int x,  vector<int>& quantities){
        int check = 0;

        for(auto it: quantities){
            check += (it + x - 1) / x;
            if (check > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
     int l = 1, r= *max_element(quantities.begin(),quantities.end());   
     while(l<r){
        int mid = (l+r)/2;
        if(isPossible(n,mid,quantities)){
            r = mid;
        }
        else{
            l=mid+1;
        }
     }
     return r;
    }
};