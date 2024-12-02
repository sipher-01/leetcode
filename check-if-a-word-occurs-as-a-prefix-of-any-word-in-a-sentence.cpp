class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp = "";
        int index = 1; // Start indexing from 1 as per the problem statement

        for (int i = 0; i <= sentence.length(); i++) {
            // Add characters to the current word until a space or end of string
            if (i < sentence.length() && sentence[i] != ' ') {
                temp += sentence[i];
            } else {
                // Check if `searchWord` is a prefix of the current word
                if (temp.substr(0, searchWord.length()) == searchWord) {
                    return index;
                }
                temp = ""; // Reset temp for the next word
                index++;   // Move to the next word
            }
        }

        // If no word matches, return -1
        return -1;
    }
};