class Solution {
public:
    int countTriples(int n) {
        unordered_set<int>sq;
        for(int i=1; i<=n; i++){
            sq.insert(i*i);
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int sum = i*i + j*j;
                if(sq.find(sum)!=sq.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};