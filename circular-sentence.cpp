class Solution {
public:
    bool isCircularSentence(string sentence) {
       vector<string>word;
       string temp = "";
       for(int i=0; i<sentence.length(); i++){
        if(sentence[i]==' '){
            word.push_back(temp);
            temp = "";
            continue;
        }
        temp+=sentence[i];
       } 
       if (!temp.empty()) {
            word.push_back(temp);
        }
       char firstChar = word[0][0];
        char lastChar = word[0].back();
        
        for (int i = 1; i < word.size(); i++) {
            if (word[i][0] != lastChar) return false;
            lastChar = word[i].back();
        }
        return lastChar == firstChar;
    }
};