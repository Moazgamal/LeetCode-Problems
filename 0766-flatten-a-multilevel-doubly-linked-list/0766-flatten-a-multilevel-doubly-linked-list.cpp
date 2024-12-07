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
      
       
        Node* flatchild = flattenn(cur->child);
        Node* after = cur->next;
        if(flatchild)
        {
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child= nullptr;
            flatchild->next = after;
            if(after)
                after->prev = flatchild;
            else
                return flatchild;
        }
       return flattenn(after);
        
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