class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;
        for(int i=0; i<n; i++){
            vector<int>l(26,0);
            for(int j=i; j<n; j++){
                int ind = s[j]-'a';
                l[ind] += 1;
                int cnt = 0;
                for(int k=0; k<26; k++){
                    // cout<<l[k]<<" ";
                    if(l[k]>cnt){
                        cnt = l[k];
                    }
                }
                // cout<<endl;
                int len = 0;
                for(int k=0; k<26; k++){
                    if(l[k]==cnt){
                        len++;
                    }else if(l[k]>0 && l[k]!=cnt){
                        len = 0;
                        break;
                    }
                }
                if(len>0)ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};