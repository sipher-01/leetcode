class Node{
private: 
Node* link[26];
int count = 0;
public:
    bool contain(char c){
        return link[c-'a']!=NULL;
    }
    void put(char c,Node* node){
        link[c-'a'] = node;
    }
    Node* get(char c){
        return link[c-'a'];
    }
    void setEnd(){
        count++;
    }
    int getEnd(){
        return count;
    }
};
class Trie{
private:Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string& s){
        Node* node = root;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(!node->contain(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
            node->setEnd();
        }
    }
    int startWith(string& s){
         Node* node = root;
         int cnt = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(node->contain(c)){
            node = node->get(c);
            cnt += node->getEnd();
            }
        }
        return cnt;
    }
};


class Solution {
public:
    void prefix(string& s, vector<string>&temp){
        for(int i=0; i<s.size(); i++){
            temp.push_back(s.substr(0,i+1));
        }
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        Trie trie;
        for(auto it: words){
            trie.insert(it);
        }
        for(auto it: words){
            ans.push_back(trie.startWith(it));
        }
        return ans;
    }
};