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
    void counting(TreeNode* root, int path_max, int &res){
        if(!root) return;
        if(root->val >= path_max){
            res++;
            path_max = root->val;
        }
        counting(root->left, path_max, res);
        counting(root->right, path_max, res);

    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        counting(root, INT_MIN, res);
        return res;
    }
};
