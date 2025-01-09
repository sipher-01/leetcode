class Node{
public:
    Node* arr[26];
    int count;
    Node(){
        for(int i=0; i<26; i++){
            arr[i] = nullptr;
        }
        count=0;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void add(string& s){
        Node* curr = root;
        for(char c: s){
            int ind = c-'a';
            if(curr->arr[ind]==nullptr){
                curr->arr[ind] = new Node();
            }
            curr = curr->arr[ind];
            curr->count++;
        }
    }

    int prefixCount(string& s){
        Node* curr = root;
        for(char c: s){
            int ind = c-'a';
            if (curr->arr[ind] == nullptr) {
                return 0;
            }
            curr = curr->arr[ind];
        }
        return curr->count;
    }
};





class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // int l = pref.length();
        // int ans = 0;
        // for(auto it: words){
        //     if(it.substr(0,l) == pref)ans++;
        // }
        // return ans;
        Trie trie;
        for(auto word: words){
            trie.add(word);
        }
        return trie.prefixCount(pref);
    }
};