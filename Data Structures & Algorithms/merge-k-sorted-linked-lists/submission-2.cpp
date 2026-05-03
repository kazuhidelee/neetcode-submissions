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
        if(lists.size() == 0) return nullptr;
        int n = lists.size();
        while(n > 1){
            int index = 0;
            for(int i = 0; i < n; i += 2){
                ListNode* l1 = lists[i];
                ListNode* l2;
                if(i + 1 >= n){
                    l2 = nullptr;
                }else{
                    l2 = lists[i + 1];
                }
                ListNode* merged = merge2Lists(l1, l2);
                lists[index] = merged;
                index++;
            }
            n = index;
        }

        return lists[0];
    }
};
