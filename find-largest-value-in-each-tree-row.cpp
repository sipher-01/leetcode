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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            while(n--){
                auto it = q.front();
                q.pop();
                maxi = max(maxi,it->val);
                if(it->left!=NULL)q.push(it->left);
                if(it->right!=NULL)q.push(it->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};