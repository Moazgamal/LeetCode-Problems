class MyCircularDeque {
public:
    class Node
    {
        public :
        int val;
        Node* next {};
        Node* prev{};
    };
    int sz  =0;
    Node* head;
    Node* tail;
    int _k=0;
    MyCircularDeque(int k) {
        _k=k;
        
    }
    
    bool insertFront(int value) {
        if(sz==_k)
            return false;
        if(sz==0)
        {
            head=new Node();
            head->val = value;
            sz++;
            tail = head;
            return true;
        }
        Node* newhead = new Node();
        newhead->val  = value;
        newhead->next = head;
        head->prev = newhead;
        head = newhead;
        if(newhead->next == nullptr)
            tail= newhead;
        sz++; return true;
        
        
    }
    
    bool insertLast(int value) {
        if(sz==_k)
            return false;
        if(sz==0)
        {
            head=new Node();
            head->val = value;
            sz++;
            tail=head;
            return true;
        }
         Node* newhead = new Node();
        newhead->val  = value;
        tail->next = newhead;
        newhead->prev = tail;
        tail = newhead;
        sz++; return true;
    }
    
    bool deleteFront() {
        if(sz==0)
            return false;
        if(sz==1)
        {
            head=tail=nullptr;
            sz--;
            return true;
        }
        Node* after = head->next;
        head->next = nullptr;
        head=after;
        head->prev=nullptr;
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if(sz==0)
            return false;
        if(sz==1)
        {
            head=tail=nullptr;
            sz--;
            return true;
        }
        Node* before = tail->prev;
        tail=before;
        tail->next = nullptr;
        sz--;
        return true;
        
    }
    
    int getFront() {
        if(sz==0)
            return -1;
        return head->val;
        
        
    }
    
    int getRear() {
        if(sz==0)
            return -1;
        return tail->val;
        
    }
    
    bool isEmpty() {
        if(sz==0)
            return true;
        return false;
        
    }
    
    bool isFull() {
        if(sz==_k)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */