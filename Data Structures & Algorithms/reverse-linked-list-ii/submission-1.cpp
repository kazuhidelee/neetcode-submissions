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
        ListNode* dummy = new ListNode(0);
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* prev_ptr1 = dummy;
        dummy->next = head;
        int i = 1;
        int j = 1; 
        while(i < left || j < right){
            if(i < left){
                prev_ptr1 = ptr1;
                ptr1 = ptr1->next;
                ++i;
            }
            if(j < right){
                ptr2 = ptr2->next;
                ++j;
            }
        }
        ListNode* prev = ptr2->next;
        while(ptr1 != ptr2){
            ListNode* next = ptr1->next;
            ptr1->next = prev;
            prev = ptr1;
            ptr1 = next;
        }
        ptr2->next = prev;
        prev_ptr1->next = ptr2;
        return dummy->next;
    }
};