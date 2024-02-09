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
 class BSTIterator {
private:stack<TreeNode*>st;
//reverse false->next
//reverse true->before
bool reverse = true;
public:
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse = isreverse;
        pushall(root);
    }
    
    int next() {
        TreeNode* tp = st.top();
        st.pop();
        if(!reverse)pushall(tp->right);
        else pushall(tp->left);
        return tp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    private:
    void pushall(TreeNode* Node){
        for(;Node!=NULL;){
            st.push(Node);
            if(reverse==false)Node = Node->left;
            else Node = Node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator a(root,false);
        BSTIterator b(root,true);
        int l = a.next();
        int r = b.next();
        while(l<r){
            if(l+r==k)return true;
            else if(l+r>k)r=b.next();
            else l=a.next();
        }
        return false;
    }
};