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
TreeNode* build(vector<int> &preOrder,int &i,int ubound){
if(i==preOrder.size() || preOrder[i]>ubound)return nullptr;
 TreeNode* root = new TreeNode(preOrder[i++]);
 root->left = build(preOrder,i,root->val);
 root->right = build(preOrder,i,ubound);
 return root;
} 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     int i=0;
    return build(preorder,i,INT_MAX);
    }
};