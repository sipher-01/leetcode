class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long>f(n,0);

        for(int i=0; i<m; i++){
            int m = mana[i];
            long long now = f[0];
            for(int j=1; j<n; j++){
                now = max(now+skill[j-1]*m , f[j]);
            }
            f[n-1] = now + skill[n-1]*m;

            for(int k=n-2; k>=0; k--){
                f[k] = f[k+1] - skill[k+1]*m;
            }
        }
        return f[n-1];
    }
};