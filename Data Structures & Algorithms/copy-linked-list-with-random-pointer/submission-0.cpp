/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copy = head;
        unordered_map<Node*, Node*> old_to_new;
        while(copy){
            old_to_new[copy] = new Node(copy->val);
            copy = copy->next;
        }
        copy = head;
        while(copy){
            old_to_new[copy]->next = old_to_new[copy->next];
            old_to_new[copy]->random = old_to_new[copy->random];
            copy = copy->next;
        }
        return old_to_new[head];
    }
};
