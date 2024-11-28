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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* dummy1 = new ListNode(0);
        dummy1->next = list1;
        ListNode* dummy2 = new ListNode(0);
        dummy2->next = list2;
        ListNode* h1 = list1; ListNode* h2 = list2;
        ListNode* prev1 = dummy1;
        ListNode* prev2 = dummy2;
        while(h1 && h2)
        {
            if(h2->val > h1->val)
            {
                prev1 = h1; h1 = h1->next;
            }
            else
            {
                ListNode* afterh1 = h1->next;
                ListNode* afterh2 = h2->next;
                prev1->next = h2;
                prev1 = h2;
                h2->next = h1;
                prev2->next = afterh2;
                h2 = afterh2;
            }
        }
        if(h2)
            prev1->next = h2;
        return dummy1->next;
        
    }
};