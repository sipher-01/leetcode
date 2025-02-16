class Solution {
    unordered_map<int,int>freq;
public:
    bool check(int num, int ind, unordered_map<int,int>&mp){
        if(mp.find(num)!=mp.end()){
            if(num==1)return false;
            if(freq[num]==2)return false;
            int diff = ind - mp[num];
            if(diff==num)return true;
            else return false;
        }
        return true;
    }
    // bool solve(int i,int n, vector<int>&res, unordered_map<int,int>&mp){
    //     if(i==res.size())return true;

    //     for(int j=n; j>=1; j--){
    //         if(check(j,i,mp)){
    //             int num = -1;
    //             if(mp.find(j)!=mp.end()){
    //                 num = mp[j];
    //             }
    //             freq[j]++;
    //             mp[j] = i;
    //             res[i] = j;
    //             if(solve(i+1,n,res,mp))return true;
    //             if(num==-1)mp.erase(j);
    //             else mp[j] = num;
    //             res[i] = 0;
    //             freq[j]--;
    //         }
    //     }
    //     return false;
    // }
    bool solve(int i, int n, vector<int>& res, vector<bool>& used){
        if(i==res.size())return true;
        if(res[i]!=0)return solve(i+1,n,res,used);

        for(int num=n; num>=1; num--){
            if(used[num])continue;
            int j = (num==1)?i:i+num;
            if(j<res.size() && res[j] == 0){
                used[num]= true;
                res[i] = num;
                res[j] = num;
                if (solve(i+1,n,res,used))return true;
                used[num] =false;
                res[i]=0;
                res[j]=0; 
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(n*2-1,0);
        // unordered_map<int,int>mp;
        vector<bool>used(n+1,false);
        solve(0,n,res,used);
        return res;
    }
};