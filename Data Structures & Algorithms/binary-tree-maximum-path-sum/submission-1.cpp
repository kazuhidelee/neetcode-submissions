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
    int find_max(TreeNode* root, int &res){
        if(!root) return 0;

        int left = max(0, find_max(root->left, res));
        int right = max(0, find_max(root->right, res));

        res = max(res, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        find_max(root, res);
        return res;
    }
};
