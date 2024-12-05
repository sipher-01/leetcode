class Solution {
public:
    bool solve(string &start,string &target,unordered_map<string,bool>&mp){
            if(start==target)return true;

        if(mp.count(start)){
            return mp[start];
        }
        for(int i=0; i<start.length(); i++){
            if(start[i]=='L' && i>0 && start[i-1]=='_'){
                swap(start[i],start[i-1]);
                if(solve(start,target,mp))return true;
                swap(start[i],start[i-1]);
            }
            else if(start[i]=='R' && i<start.length()-1 && start[i+1]=='_'){
                swap(start[i],start[i+1]);
                if(solve(start,target,mp))return true;
                swap(start[i],start[i+1]);
            }
        }
        return mp[start]=false;;
    }
    bool canChange(string start, string target) {
        int n = start.length();
        int m = target.length();
        if(n!=m)return false;
        // unordered_map<string,bool>mp;
        // return solve(start,target,mp);
        int i=0,j=0;
        while(i<n || j<n){
            while(start[i]=='_')i++;
            while(target[j]=='_')j++;
            if(i==n || j==n)return i==n && j==n;
            if(start[i]!=target[j])return false;
            if(start[i]=='L' && j>i)return false;
            if(start[i]=='R' && i>j)return false;
            i++;j++;
        }
        return true;

    }
};