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
    int solve(vector<int>& t){
        unordered_map<int,int>mp;
        vector<int>sa(t.begin(),t.end());
        sort(sa.begin(),sa.end());
        int ans = 0;
        for(int i=0; i<t.size(); i++){
            mp[t[i]] = i;
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] == sa[i])continue;
            int ind = mp[sa[i]];
            mp[t[i]] = ind;
            mp[t[ind]] = i;
            swap(t[i],t[ind]);
            ans++;
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res += solve(temp);
        }
        return res;
    }
};