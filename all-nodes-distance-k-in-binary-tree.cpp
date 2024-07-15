/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_track(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent_track(root,parent);
        unordered_map<TreeNode*,bool>visit;
        queue<TreeNode*>q;
        q.push(target);
        visit[target]=true;
        int dist = 0;
        while(!q.empty()){
            int s = q.size();
            if(dist++ == k) break;
            for (int i=0; i<s; i++){
            TreeNode* curr = q.front();
            q.pop();
                if(curr->left && !visit[curr->left]){
                    q.push(curr->left);
                    visit[curr->left]=true;
                }
                if(curr->right && !visit[curr->right]){
                    q.push(curr->right);
                    visit[curr->right]=true;
                }
                if(parent[curr] && !visit[parent[curr]]){
                    q.push(parent[curr]);
                    visit[parent[curr]]=true;
                }

            }

        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};