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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return nullptr;
        ListNode* ans = new ListNode();
        if(l1)
        {
            ans->val = l1->val; l1 = l1->next;
        }
        if(l2)
        {
            ans->val += l2->val;
            l2 = l2->next;
        }
        
        ListNode* ansCpy = ans;
        int carry = (ans->val)/10; 
        ans->val %= 10;
        while(l1 && l2)
        {
            ansCpy->next = new ListNode();
            ansCpy->next->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            ansCpy = ansCpy->next; 
            l1 = l1->next; l2 = l2->next;
        }
        while(l1)
        {
            ansCpy->next = new ListNode(); 
            ansCpy->next->val = (l1->val+carry)%10;
            carry = (l1->val + carry)/10;
            ansCpy = ansCpy->next; l1 = l1->next;
        }
        while(l2)
        {
            ansCpy->next = new ListNode(); 
            ansCpy->next->val = (l2->val+carry)%10;
            carry = (l2->val + carry)/10;
            ansCpy = ansCpy->next; l2 = l2->next;
        }
        if(carry)
            ansCpy->next = new ListNode(carry);

        return ans; 
        
    }
};