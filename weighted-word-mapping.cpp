class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(auto word: words){
            int weight = 0;
            for(auto c: word){
                weight += weights[c-'a'];
            }
            weight %= 26;
            char c = 'a' + (25 - weight);
            s += c;
        }
        return s;
    }
};