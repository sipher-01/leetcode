#define ll long long 
class Solution {
public:
    ll dividePlayers(vector<int>& skill) {
        int n = skill.size();
        ll sum = accumulate(skill.begin(),skill.end(),0);
        ll target = -1;
        if(sum % (n/2) != 0)return target;
        else  target = sum / (n/2);
        vector<pair<int,int>>team;
        int i=0, j=n-1;
        sort(skill.begin(),skill.end());
        while(i<j){
            if(skill[i]+skill[j]==target){
                team.push_back({skill[i],skill[j]});
                i++;
                j--;
            }
            else if(skill[i]+skill[j]<target)i++;
            else j--;
        }
        if (team.size() != n / 2) return -1;
        ll ans = 0;
        for(auto it: team){
            ans += (it.first*it.second);
        }
        return ans;
    }
};