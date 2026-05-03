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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                dummy->next = ptr1;
                ptr1 = ptr1->next;
            }else{
                dummy->next = ptr2;
                ptr2 = ptr2->next;
            }
            dummy = dummy->next;
        }
        if(ptr1) dummy->next = ptr1;
        if(ptr2) dummy->next = ptr2;
        return result->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for(ListNode* l: lists){
            res = merge2Lists(res, l);
        }
        return res;
    }
};
