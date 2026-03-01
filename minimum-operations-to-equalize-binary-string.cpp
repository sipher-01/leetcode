class Solution {
public:
    int minOperations(string s, int k) {
        set<int>odd;
        set<int>even;
        int n = s.length();
        int z = 0;

        for(char &c: s){
            if(c=='0')z += 1;
        }
        if(z==0)return 0;
        
        for(int i=0; i<n; i++){
            if(i%2){
                odd.insert(i);
            }else{
                even.insert(i);
            }
        }

        queue<int>q;
        q.push(z);
        vector<int>op(n+1,-1);
        op[z] = 0;
        if(z%2==0){
            even.erase(z);
        }else{
            odd.erase(z);
        }
        while(!q.empty()){
            int state = q.front();
            q.pop();
            int minF = max(0,k-n+state);
            int maxF = min(k,state);
            int maxZ = state + k - (2*minF);
            int minZ = state + k - (2*maxF);
            auto &curr = minZ%2==0?even:odd;
            auto it = curr.lower_bound(minZ);
            while(it!=curr.end() && *it<=maxZ){
                if(op[*it]==-1){
                    op[*it] = op[state] + 1;
                }
                if(*it == 0)return op[0];
                q.push(*it);
                it = curr.erase(it);
            }
        }
        return -1;
    }
};