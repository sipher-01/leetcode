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
    int maxLevelSum(TreeNode* root) {
        int res = 0;
        int sum = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            int levelSum = 0;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            } 
            if(levelSum > sum){
                res = level;
                sum = levelSum;
            }
            level++;
        }
        return res;
        
    }
};