public class MyCircularDeque {
    public class Node
    {
        
        public int val =0;
        public Node next = null;
        public Node prev = null;
    };
    public Node head;
    public int sz  =0;
    public Node tail;
    public int _k=0;

    public MyCircularDeque(int k) {
        _k=k;
    }
    
    public bool InsertFront(int value) {
        if(sz==_k)
            return false;
        if(sz==0)
        {
            head=new Node();
            head.val = value;
            sz++;
            tail = head;
            return true;
        }
        Node newhead = new Node();
        newhead.val  = value;
        newhead.next = head;
        head.prev = newhead;
        head = newhead;
        if(newhead.next == null)
            tail= newhead;
        sz++; return true;
        
    }
    
    public bool InsertLast(int value) {
        if(sz==_k)
            return false;
        if(sz==0)
        {
            head=new Node();
            head.val = value;
            sz++;
            tail=head;
            return true;
        }
         Node newhead = new Node();
        newhead.val  = value;
        tail.next = newhead;
        newhead.prev = tail;
        tail = newhead;
        sz++; return true;
        
    }
    
    public bool DeleteFront() {
        if(sz==0)
            return false;
        if(sz==1)
        {
            head=tail=null;
            sz--;
            return true;
        }
        Node after = head.next;
        head.next = null;
        head=after;
        head.prev=null;
        sz--;
        return true;
        
    }
    
    public bool DeleteLast() {
        if(sz==0)
            return false;
        if(sz==1)
        {
            head=tail=null;
            sz--;
            return true;
        }
        Node before = tail.prev;
        tail=before;
        tail.next = null;
        sz--;
        return true;
        
    }
    
    public int GetFront() {
        if(sz==0)
            return -1;
        return head.val;
    }
    
    public int GetRear() {
        if(sz==0)
            return -1;
        return tail.val;
        
    }
    
    public bool IsEmpty() {
        if(sz==0)
            return true;
        return false;
    }
    
    public bool IsFull() {
        if(sz==_k)
            return true;
        return false;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.InsertFront(value);
 * bool param_2 = obj.InsertLast(value);
 * bool param_3 = obj.DeleteFront();
 * bool param_4 = obj.DeleteLast();
 * int param_5 = obj.GetFront();
 * int param_6 = obj.GetRear();
 * bool param_7 = obj.IsEmpty();
 * bool param_8 = obj.IsFull();
 */