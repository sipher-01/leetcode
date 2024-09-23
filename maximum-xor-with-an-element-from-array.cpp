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
            else
                node = node->get(bit);
        }
        return m;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // vector<pair<int,pair<int,int>>>oQ;
        // for(int i=0; i<queries.size(); i++){
        //     oQ.push_back({queries[i][1],{queries[i][0],i}});
        // }
        // sort(oQ.begin(),oQ.end());
        // Trie trie;
        // vector<int>ans(queries.size(),0);
        // for(auto it: oQ){
        //     int a = it.first;
        //     int x = it.second.first;
        //     int ind = it.second.second;
        //     int i=0;
        //     while(i<nums.size() && nums[i]<=a){
        //         trie.insert(nums[i]);
        //         i++;
        //     }
        //     if(i==0)ans[ind] = -1;
        //     else ans[ind] = trie.maxi(x);
        // }
        // return ans;
       int n = (int) queries.size();
        vector<int> ans(n, -1);
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);     
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][1] < queries[j][1];
        });
        
        sort(nums.begin(), nums.end());
        Trie t;
        int st = 0;
        for (int i = 0; i < n; ++i) {
            int x = queries[idx[i]][0];
            int m = queries[idx[i]][1];
            while (st < (int) nums.size() && nums[st] <= m) {
                t.insert(nums[st]);
                st++;
            }
            ans[idx[i]] = (st ? t.maxi(x) : -1);
        }
        return ans;
    }
};