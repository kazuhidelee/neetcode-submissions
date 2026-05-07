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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &ptr, int l, int r){
        if (l > r) return nullptr;
        //1. Take preorder[preorder_ptr] as root
        TreeNode* new_node = new TreeNode(preorder[ptr]);
        //2. Move preorder_ptr forward
        int curr;
        //3. Find root in inorder
        for(int i = 0; i < inorder.size(); ++i){
            if(inorder[i] == preorder[ptr]){
                curr = i;
                break;
            }
        }
        ptr++;
        // 4. Build left from l to mid - 1
        new_node->left = build(preorder, inorder, ptr, l, curr - 1);
        // 5. Build right from mid + 1 to r
        new_node->right = build(preorder, inorder, ptr, curr + 1, r);
        return new_node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int curr = 0;
        return build(preorder, inorder, curr, 0, inorder.size() - 1);

    }
};
