class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        if(mp.size()<k)return "";
        int cnt=0;
        string ans;
        // for(auto it: mp){
        //     if(cnt==k)return it;
        //     if(mp[it]==1)cnt++;
        // }
        for (const string& str : arr) {
            if (mp[str] == 1) {
                cnt++;
                if (cnt == k) {
                    return str;
                }
            }
        }
        return "";
    }
};