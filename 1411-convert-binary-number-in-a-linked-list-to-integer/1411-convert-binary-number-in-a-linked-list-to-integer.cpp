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
    int getDecimalValue(ListNode* head) {
        int sum = 0; 

        while(head)
        {
            if(head->next)
            {
                sum *= 2;
                if(head->val == 1)
                    sum+=2;
            }
            else
            {
                if(head->val ==1)
                    sum +=1;
            }
            head = head->next;
        }return sum ;
        
    }
};