/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* headACpy = headA;
        while(headA)
        {
            headA->val += 100000; 
            headA= headA->next;
        }
        ListNode* ans = nullptr;
        while(headB)
        {
            if(headB->val > 100000)
            {
                ans = headB; break;
            }
            headB = headB->next;
        }
        ListNode* it = ans;
        while(it)
        {
            it->val -= 100000;
            it = it->next;
        }
        while(headACpy != ans)
        {
            headACpy->val -= 100000;
            headACpy = headACpy->next;
        }
        return ans;
    }
};