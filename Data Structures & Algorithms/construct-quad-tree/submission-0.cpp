/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* helper(vector<vector<int>>& grid, int start_r, int end_r, int start_c, int end_c){
        int val = grid[start_r][start_c];
        bool same = true;
        for(int i = start_r; i <= end_r; ++i){
            for(int j = start_c; j <= end_c; ++j){
                if(grid[i][j] != val){
                    same = false;
                    break;
                }
            }
        }
        if(same){
            return new Node(val, true);
        }else{
            Node* curr = new Node(val, false);
            curr->topLeft = helper(grid, start_r, (start_r + end_r) / 2, start_c, (start_c + end_c) / 2);
            curr->topRight = helper(grid, start_r, (start_r + end_r) / 2, (start_c + end_c) / 2 + 1, end_c);
            curr->bottomLeft = helper(grid, (start_r + end_r) / 2 + 1, end_r, start_c, (start_c + end_c) / 2);
            curr->bottomRight = helper(grid, (start_r + end_r) / 2 + 1, end_r, (start_c + end_c) / 2 + 1, end_c);
            return curr;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};