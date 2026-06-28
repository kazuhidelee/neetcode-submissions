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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;
        ListNode* before = dummy;
        ListNode* after;
        dummy->next = head;
        for(int i = 1; i < right; ++i){
            if(i < left){
                before = curr;
                curr = curr->next;
            }else{
                after = curr->next;
                curr->next = after->next;
                after->next = before->next;
                before->next = after;
            }
        }
        
        return dummy->next;
    }
};