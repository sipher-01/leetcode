/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>children;
        for(auto &it: descriptions){
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];
            children.insert(child);
            if(mp.find(parent)==mp.end()){
                TreeNode* p = new TreeNode(parent);
                mp[parent] = p;
            }
            if(mp.find(child)==mp.end()){
                TreeNode* c = new TreeNode(child);
                mp[child] = c;
            }
            if(isLeft){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }

        }
        TreeNode* root;
        for(auto it: mp){
            if(children.find(it.first)==children.end()){
                root = it.second;
            }
        }
        return root;
    }
};