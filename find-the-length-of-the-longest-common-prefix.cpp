class Node{
    Node* link[10];
public:
    bool contain(char c){
        return link[c-'0']!=NULL;
    }
    void put(char c, Node* node){
        link[c-'0'] = node;
    }
    Node* get(char c){
        return link[c-'0'];
    }
};
class Trie{
Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string num){
        Node* node = root;
        for(int i=0; i<num.size(); i++){
            char c = num[i];
            if(!node->contain(c)){
                node->put(c,new Node());
            }
            node = node->get(c);
        }
    }
    int maxi(string num){
        Node* node = root;
        int cnt = 0;
        for(int i=0; i<num.size(); i++){
            char c = num[i];
            if(node->contain(c)){
                cnt++;
                node = node->get(c);
            }
            else break;
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int len = 0;
        Trie trie;
        for(auto it: arr1){
            string a = to_string(it);
            trie.insert(a);
        }
        for(auto it: arr2){
            string a = to_string(it);
            len = max(len,trie.maxi(a));
        }
        return len;
    }
};