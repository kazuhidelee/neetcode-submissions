/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* iter = head;
        while(iter){
            nodes.push_back(iter);
            iter = iter->next;
        }
        int l = 0;
        int r = nodes.size() - 1;
        while(l < r){
            nodes[l]->next = nodes[r];
            ++l;
            nodes[r]->next = nodes[l];
            --r;
        }
        nodes[l]->next = nullptr;
    }
};
