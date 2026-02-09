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
    vector<TreeNode*>a;
public:
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        a.push_back(root);
        inorder(root->right);

    }
    TreeNode* solve(int start, int end){
        if(start>end){
            return NULL;
        }
        int mid = (start + end)/2;
        TreeNode* root = a[mid];
        TreeNode* left = solve(start,mid-1);
        TreeNode* right = solve(mid+1,end);

        return new TreeNode(root->val,left,right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return solve(0,a.size()-1);
    }
};