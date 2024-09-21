class Node{
private:
    Node* link[26];
    bool flag = false;
public:
    bool contain(char c){
        return link[c-'a']!=NULL;
    }
    void put(char c, Node* node){
        link[c-'a'] = node;
    }
    Node* get(char c){
        return link[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};


class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            if(!node->contain(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i =0; i<word.size(); i++){
            char c = word[i];
            if(!node->contain(c)){
                return false;
            }
            node = node->get(c);
        }
        return node->isEnd(); 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i =0; i<prefix.size(); i++){
            char c = prefix[i];
            if(!node->contain(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */