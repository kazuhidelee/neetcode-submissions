/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        // original -> new
        unordered_map<Node*, Node*> mapping;
        queue<Node*> bfs;
        bfs.push(node);
        mapping[node] = new Node(node->val);
        while(!bfs.empty()){
            Node* curr = bfs.front();
            bfs.pop();
            for(Node* n: curr->neighbors){
                if(mapping.find(n) == mapping.end()){
                    bfs.push(n);
                    mapping[n] = new Node(n->val);
                }
                mapping[curr]->neighbors.push_back(mapping[n]);
            }
        }
        return mapping[node];

    }
};
