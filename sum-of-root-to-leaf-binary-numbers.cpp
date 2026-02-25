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
    int ans;
public:
    int to_num(vector<int>&a){
        reverse(begin(a),end(a));
        int res = 0;
        int val = 1;
        for(int i=0; i<a.size(); i++){
            res += a[i] * val;
            val = val<<1;
        }
        return res;
    }
    void solve(TreeNode* root,vector<int>a){
        if(!root)return;
        a.push_back(root->val);
        if(!root->left && !root->right){
            // int num = to_num(a);
            // cout<<to_num(a)<<" ";
            ans += to_num(a);
            // cout<<ans<<endl;
            return ;
        }
        solve(root->left,a);
        solve(root->right,a);
        a.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        solve(root,{});
        return ans;
    }
};