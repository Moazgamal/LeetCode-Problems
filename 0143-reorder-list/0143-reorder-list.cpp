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
    void reorderList(ListNode* head) {

        int sz = 0; 
        ListNode* headCpy = head;
        ListNode* prev = nullptr;
        while(headCpy)
        {
            sz++;
            prev = headCpy ;
            headCpy = headCpy->next;
        }
        ListNode* tail = prev;
        headCpy = head;
        prev = nullptr; int i = 0; 
        while(headCpy)
        {
            if(i >= sz/2 +1)
            {
                ListNode* after = headCpy->next;
                headCpy->next = prev;
                prev = headCpy;
                headCpy = after;
            }
            else
            {
                prev = headCpy; 
                headCpy = headCpy->next;
            }i++;
        }
        headCpy = head;
        sz = sz%2 ==0 ? sz/2-1 : sz/2;
        while(sz--)
        {
            ListNode* afterhead = headCpy->next;
            ListNode* prevtail = tail->next;
            headCpy->next = tail;
            tail->next = afterhead;
            tail = prevtail;
            headCpy = afterhead;
        }
        tail->next = nullptr;
        

        

        
    }
};