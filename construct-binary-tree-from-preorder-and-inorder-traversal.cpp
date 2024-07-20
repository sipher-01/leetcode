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
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     unordered_map<int,int>mp;
    //     for(int i=0; i<inorder.size(); i++){
    //         mp[inorder[i]]=i;
    //     }
    //     return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    // }
    // TreeNode* solve(vector<int>& preorder, int preStart, int preEnd,  vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>mp){
    //     if(preStart>preEnd || inStart>inEnd)return nullptr;
    //     TreeNode* root = new TreeNode(preorder[preStart]);
    //     int inroot = mp[root->val];
    //     int leftNodes = inroot-inStart;
    //     root->left = solve(preorder,preStart+1,preStart+leftNodes,inorder,inStart,inroot-1,mp);
    //     root->right = solve(preorder,preStart+leftNodes+1,preEnd,inorder,inroot+1,inEnd,mp);
    // return root;
    // }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }

    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr; // Base case: if the indices are out of bounds, return NULL
        }

        TreeNode* root = new TreeNode(preorder[preStart]); // Create the root node with the current root value from preorder
        int inRoot = mp[root->val]; // Find the index of the root in the inorder sequence
        int leftNodes = inRoot - inStart; // Calculate the number of nodes in the left subtree

        // Recursively build the left and right subtrees
        root->left = solve(preorder, preStart + 1, preStart + leftNodes, inorder, inStart, inRoot - 1, mp);
        root->right = solve(preorder, preStart + leftNodes + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

        return root; // Return the constructed tree
    }
};