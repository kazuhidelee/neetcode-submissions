class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }

    int dfs(TreeNode* node, int &k) {
        if (!node) return -1;

        int left = dfs(node->left, k);
        if (k == 0) return left;

        k--;
        if (k == 0) return node->val;

        return dfs(node->right, k);
    }
};
