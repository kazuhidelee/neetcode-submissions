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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* prev_tail = nullptr;
        while(ptr){
            ListNode* checking = ptr;
            bool has_k = true;
            for(int i = 0; i < k; ++i){
                if(!checking) {
                    has_k = false;
                    break;
                }
                checking = checking->next;
            }
            if(!has_k) break;
            ListNode* prev = nullptr;
            // beginning of the reverse
            ListNode* begin = ptr;
            ListNode* temp;
            for(int i = 0; i < k; ++i){
                temp = ptr->next;
                ptr->next = prev;
                prev = ptr;
                ptr = temp;
            }
            // first group
            if(!prev_tail){
                head = prev;
                prev_tail = begin;
            }else{
                prev_tail->next = prev;
                prev_tail = begin;
            }
            
            begin->next = temp;
        }
        return head;
    }
};
