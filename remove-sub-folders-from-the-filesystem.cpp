class Node{
    Node* links[27];
    bool flag = false;
public:
    bool containKey(char c) {
        if (c == '/') return links[26] != NULL; 
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, Node* node) {
        if (c == '/') links[26] = node; 
        else links[c - 'a'] = node;
    }

    Node* get(char c) {
        if (c == '/') return links[26];
        return links[c - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};
class Trie{
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void Insert(string s){
        Node* node = root;
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s[i];
            if(!node->containKey(c)){
                 node->put(c,new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(string s){
        Node* node = root;
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s[i];
           if (!node->containKey(c)) return false;
            node = node->get(c);
            if (node->isEnd()) return true;
        }
        return false;
    }

};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        const int n=folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans={folder[0]};
    //    ans.reserve(40000);
        string prev=folder[0];
        for(int i=1; i<n; i++){
            string s=folder[i];
            if (s.find(prev+'/')!=0){
                ans.push_back(s);
                prev=s;
            }
        }
        return ans;
    }
};

