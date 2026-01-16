class Solution {
    using ll = long long;
public:
const int mod = 1e9+7; 
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        unordered_set<int>l;
        for(int i = 0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                l.insert((vFences[j] - vFences[i]));
            }
        }
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end());
        int res  = 0;
        for(int i = 0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                if(l.count((hFences[j] - hFences[i]))){
                    res = max(res,(hFences[j] - hFences[i]));
                }
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = (1ll * res * res) % mod;
        }
        return res;
    }
};