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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            TreeNode* curr = bfs.front();
            bfs.pop();
            if(curr){
                res += to_string(curr->val);
                res += ' ';
            }else{
                res += '_';
                res += ' ';
                continue;
            }
        
            bfs.push(curr->left);
            bfs.push(curr->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        ss >> token;
        queue<TreeNode*> bfs;
        if(token == "_") return nullptr;
        TreeNode* head = new TreeNode(stoi(token));
        bfs.push(head);
        while(!bfs.empty()){
            TreeNode* curr = bfs.front();
            bfs.pop();
            ss >> token;
            if(token == "_"){
                curr->left = nullptr;
            }else{
                curr->left = new TreeNode(stoi(token));
            }
            ss >> token;
            if(token == "_"){
                curr->right = nullptr;
            }else{
                curr->right = new TreeNode(stoi(token));
            }
            if(curr->left) bfs.push(curr->left);
            if(curr->right) bfs.push(curr->right);
        }
        return head;
    }
};
