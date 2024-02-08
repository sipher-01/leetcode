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
    int inorder(TreeNode *root, int k){
    int cnt=0;
    TreeNode* curr = root;
    vector<int>inorder;
    while(curr!=NULL){
        // if(cnt==k)return curr->data;
        if(curr->left == NULL){
            // cnt++;
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* temp = curr->left;
            while(temp->right && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right=NULL;
                // cnt++;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

return inorder[k-1];
}
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};