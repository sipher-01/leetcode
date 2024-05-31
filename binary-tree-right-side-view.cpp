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
    void dfs(TreeNode* root,map<int,int>&mp,int level){
    if(!root)return;
    // if(mp.find(level)==mp.end() || level == mp.first){
        mp[level] = root->val;
    // }
    if(root->left)dfs(root->left,mp,level+1);
    if(root->right)dfs(root->right,mp,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    map<int,int>mp;
    dfs(root,mp,0);
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
    }
};