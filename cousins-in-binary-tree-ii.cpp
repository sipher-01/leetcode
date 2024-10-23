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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     int sum = 0;
        //     for(int i=0; i<n; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         sum += node->val;
        //         if(node->left)q.push(node->left);
        //         if(node->right)q.push(node->right);
        //     }
        //     levelSum.push_back(sum);
        // }
        int levelSum = root->val;
        while(!q.empty()){
            int n = q.size();
            int nextLevel = 0;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                node->val = levelSum - node->val;
                int sibling = 0;
                if(node->left)sibling += node->left->val;
                if(node->right)sibling += node->right->val;
                if(node->left){
                    nextLevel += node->left->val;
                    node->left->val = sibling;
                    q.push(node->left);
                }
                if(node->right){
                    nextLevel += node->right->val;
                    node->right->val = sibling;
                    q.push(node->right);
                }
            }
            levelSum = nextLevel;

        }
        return root;
    }
};