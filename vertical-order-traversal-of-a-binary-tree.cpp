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
    void dfs(TreeNode* root,map<int,map<int,multiset<int>>> &mp, int step, int level){
        if(!root)return;
        mp[step][level].insert(root->val);
        if(root->left)dfs(root->left,mp,step-1,level+1);
        if(root->right)dfs(root->right,mp,step+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp; //map<col,val>
        dfs(root,mp,0,0);
        for (auto it: mp){
            auto mp1 = it.second;
            vector<int>temp;
            for(auto it2 : mp1){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};