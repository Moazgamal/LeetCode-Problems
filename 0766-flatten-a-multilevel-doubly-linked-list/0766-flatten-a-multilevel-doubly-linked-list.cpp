/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* flattenn(Node* cur)
    {
        if(!cur)
            return nullptr;
        if(!cur->child && !cur->next)
            return cur;
        if(!cur->child)
        {
            return flattenn(cur->next);
        }
        Node* ch = cur->child;
        Node* after = cur->next;
        ch->prev = cur;
        cur->next = ch;
        Node* flattchild = flattenn(cur->next);
        if(flattchild)
         {  
            
                flattchild->next = after;
            if(after)
                after->prev = flattchild;
         }
        cur->child = nullptr;
        if(after)
            return flattenn(after);
        return flattchild;
        
    }
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* dummy = new Node();
        dummy->next = head;
        flattenn(head);
        return dummy->next;
        
    }
};