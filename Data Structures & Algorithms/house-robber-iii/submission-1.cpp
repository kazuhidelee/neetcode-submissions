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
    unordered_map<TreeNode*, unordered_map<bool, int>> memo;
    int bfs(TreeNode* root, bool robbed){
        if(!root) return 0;
        if(memo.count(root) && memo[root].count(robbed)){
            return memo[root][robbed];
        }
        int not_rob = bfs(root->right, false) + bfs(root->left, false);
        if(robbed){
            memo[root][robbed] = robbed;
            return not_rob;
        }else{
            int rob = root->val + bfs(root->right, true) + bfs(root->left, true);
            memo[root][robbed] = max(rob, not_rob);
            return max(rob, not_rob);
        }

    }

    int rob(TreeNode* root) {
        return bfs(root, false);
    }
};