class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int> count(3, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        if (*min_element(count.begin(), count.end()) < k) {
            return -1;
        }
        int l =0 ; 
        int ans = INT_MAX;
        for(int r=0; r<n; r++){
            count[s[r]-'a']--;
            while(*min_element(count.begin(),count.end())<k){
                count[s[l]-'a']++;
                l++;
            }
            ans = min(ans,(n-(r-l+1)));
        }
        return ans;
    }
};