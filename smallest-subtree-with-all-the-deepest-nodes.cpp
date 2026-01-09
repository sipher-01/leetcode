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
    unordered_map<TreeNode*, int>depth;
public:

    TreeNode* solve(TreeNode* root, int level){
        depth[root] = level;
        if(!root->left && !root->right){
            return root;
        }
        TreeNode *l=NULL, *r=NULL;
        if(root->left)l = solve(root->left,level+1);
        if(root->right)r = solve(root->right,level+1);
        cout<<l<<" : "<<depth[l]<<" " <<r<<" : "<<depth[r];
        if(depth[l]>depth[r]){
            cout<<" return "<<l->val<<endl;
            return l;
        }
        else if(depth[l]==depth[r]){
            cout<<" return "<<root->val<<endl;
            depth[root] = depth[l];
            return root;
        }
        cout<<" return "<<r->val<<endl;
        return r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* start = solve(root,0); 
        return start;
    }
};