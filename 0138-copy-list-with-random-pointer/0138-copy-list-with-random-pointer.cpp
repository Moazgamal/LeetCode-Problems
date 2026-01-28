/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* x = new Node(head->val);
        Node* y = x;
        Node* headCpy = head;
        unordered_map<Node*, int>mp;
        unordered_map<Node*, int>mp2;
        unordered_map<int, Node*>mp4;
        unordered_map<int, int>mp3;
        int idx = 0; 
        while(headCpy)
        {
            if(headCpy->next)
                x->next = new Node(headCpy->next->val);
            mp[headCpy] = idx;
            headCpy = headCpy->next;
            mp2[x]=idx;
            mp4[idx] = x;
            x = x->next;
            idx++;
        }
        headCpy  = head;
        idx = 0; 
        while(headCpy)
        {
            if(headCpy->random)
                mp3[idx] = mp[headCpy->random];
            else
                mp3[idx] = -1; 
            headCpy = headCpy->next;
            idx++;
        }
        x = y;
        idx = 0; 
        while(x)
        {
            if(mp3[idx] != -1)
                x->random = mp4[mp3[idx]];
            idx++;
            x=x->next;
        }
        return y; 
    }
};