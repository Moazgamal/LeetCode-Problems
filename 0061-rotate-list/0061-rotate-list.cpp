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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
            return head;

        int len = 0; 
        ListNode* headCopy = head;
        ListNode* tail = nullptr;
        while(headCopy)
        {
            len++;
            tail = headCopy;
            headCopy = headCopy->next;
        }
        k = k%len;
        if(k == 0)
            return head;
        int moves = len-k;
        headCopy = head;
        while(--moves)
            headCopy = headCopy->next;
        ListNode* newHead = headCopy->next;
        headCopy ->next = nullptr;
        tail->next = head;
        return newHead; 

    }
};