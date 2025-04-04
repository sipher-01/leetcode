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
    int maxD = -1;
public:
    void preorder(TreeNode* root, unordered_map<int,int>&mp,int d){
        if(root==NULL){
            return;
        }
        maxD = max(maxD, d);
        mp[root->val] = d;
        if(root->left)preorder(root->left,mp,d+1);
        if(root->right)preorder(root->right,mp,d+1);
    }
    TreeNode* lca(TreeNode* root, unordered_map<int,int>&mp){
        if(root==NULL){
            return NULL;
        }
        if(mp[root->val]==maxD){
            return root;
        }
        TreeNode* left = lca(root->left,mp);
        TreeNode* right= lca(root->right,mp);
        if(left && right){
            return root;
        }
        return left?left:right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int>mp;
        preorder(root,mp,0);
        return lca(root,mp);
    }
};