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
bool  flag ;
    int balanced(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int left = balanced(root->left);
        int right = balanced(root->right);
        int diff = abs(left - right);
        if(diff > 1)flag = false;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        flag = true;
        balanced(root);
        return flag;
    }
};