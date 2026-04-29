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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* nth = dummy;
        ListNode* tail = dummy;
        int counter = 0;
        while(tail && counter < n){
            tail = tail->next;
            counter++;
        }
        ListNode* prev = nullptr;
        while(tail){
            tail = tail->next;
            prev = nth;
            nth = nth->next;
        }
        prev->next = nth->next; 
        return dummy->next;
    }
};
