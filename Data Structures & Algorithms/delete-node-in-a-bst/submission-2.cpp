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
    TreeNode* find_successor(TreeNode* node){
        while(node->left){
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key){
            if(!root->left){
                return root->right;
            }else if(!root->right){
                return root->left;
            }else{
                TreeNode* successor = find_successor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, root->val);
                return root;
            }
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }else{
            root->left = deleteNode(root->left, key);
            return root;
        }
    }
};