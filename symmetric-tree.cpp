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
    bool dfs(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL)return true;
        if(!l || !r)return false;
        if(l->val != r->val)return false;
        bool t = dfs(l->left,r->right);
        bool t1 = dfs(l->right,r->left);
        return t && t1;
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};