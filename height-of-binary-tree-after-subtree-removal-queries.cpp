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
int level[100001];
int height[100001];
int levelMax[100001];
int levelSecondMax[100001];
    int find_height(TreeNode* root, int l){
        if(root==NULL)return 0;
        level[root->val] = l;
        height[root->val] = max(find_height(root->left,l+1),
        find_height(root->right,l+1)) + 1;
        if(levelMax[l]<height[root->val]){
            levelSecondMax[l] = levelMax[l];
            levelMax[l] = height[root->val];
        }
        else if (height[root->val] > levelSecondMax[l]) {
            levelSecondMax[l] = height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // fill(begin(levelMax), end(levelMax), -1);
        // fill(begin(levelSecondMax), end(levelSecondMax), -1);
        int maxHeight = find_height(root,0);
        vector<int>res;
        for(auto a: queries){
            int L = level[a];
            int H = levelMax[L] == height[a] ? levelSecondMax[L] : levelMax[L];
            res.push_back(L+H-1);
        }
        return res;
    }
};