class Solution {
public:
    int fact(int x){
        if(x<=1)return 1;
        return x*fact(x-1);
    }
    int comb(int x){
        // int fx= fact(x);
        // int f = fact(x-2);
        // return fx/(2*f);
        return (x*(x-1))/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int tuples = 0;
        for(auto it: mp){
            if(it.second>1){
                tuples += comb(it.second);
            }
        }
        return tuples*8;
    }
};