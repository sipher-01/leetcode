class Solution {
public:
    vector<vector<int>> check(string word){
        int n = word.length();
        vector<vector<int>> lcp(n,vector<int>(n,0));

        for(int i=0; i<n; i++){
            lcp[i][n-1] = word[i]==word[n-1]?1:0;
        }

        for(int i=0; i<n; i++){
            lcp[n-1][i] = word[n-1] == word[i]?1:0;
        }

        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(word[i]==word[j]){
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                }
                else{
                    lcp[i][j] = 0;
                }
            }
        }

        return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n,'$');

        for(int i=0; i<n; i++){

            for(int j=0; j<i; j++){
                if(lcp[j][i]!=0){
                    word[i]=word[j];
                    break;
                }
            }

            if(word[i]=='$'){
                vector<bool>forbidden(26);
                for(int j=0; j<i; j++){
                    if(lcp[j][i]==0){
                        forbidden[word[j]-'a'] = true;
                    }
                }

                for(int k=0; k<26; k++){
                    if(forbidden[k]==false){
                        word[i] = k+'a';
                        break;
                    }
                }
                if(word[i]=='$'){
                    return "";
                }
            }
        }

        return check(word)==lcp?word:"";
    }
};