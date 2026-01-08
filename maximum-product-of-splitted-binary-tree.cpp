class Solution {
public:
    static const int mod = 1e9 + 7;
    long long ans = 0;

    long long traverse(TreeNode* root) {
        if (!root) return 0;
        return root->val + traverse(root->left) + traverse(root->right);
    }

    long long solve(TreeNode* root, long long total) {
        if (!root) return 0;

        long long leftsum = solve(root->left, total);
        long long rightsum = solve(root->right, total);

        long long prod1 = leftsum * (total - leftsum);
        long long prod2 = rightsum * (total - rightsum);

        ans = max(ans, max(prod1, prod2));

        return leftsum + rightsum + root->val;
    }

    int maxProduct(TreeNode* root) {
        long long total = traverse(root);
        solve(root, total);
        return ans % mod;
    }
};
