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
 #include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>>ans;
    int toggle = 1;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
            int x = q.size();
            vector<int>t;
            for(int i =x; i>0; i--)
            {
            TreeNode* temp=q.front();
            q.pop();
            t.push_back(temp->val);
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            }
            if(toggle==1){
                ans.push_back(t);
                toggle = 2;
            }
            else{
                reverse(t.begin(),t.end());
                ans.push_back(t);
                toggle = 1;
            }
    }
        return ans;
    }
};