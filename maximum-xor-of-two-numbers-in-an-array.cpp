class Node{
    Node* link[2];
public:
    bool contain(int bit){
        return link[bit]!=NULL;
    }
    void put(int bit, Node* node){
        link[bit] = node;
    }
    Node* get(int bit){
        return link[bit];
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->contain(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int maxi(int num){
        Node* node = root;
        int m = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->contain(1-bit)){
                m = m | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return m;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums){
            trie.insert(it);
        }
        int ans = 0;
        for(auto it: nums){
            ans = max(ans,trie.maxi(it));
        }
        return ans;
    }
};