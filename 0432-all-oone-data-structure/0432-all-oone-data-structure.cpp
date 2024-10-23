class AllOne {
public:
class Node
{
    public:
    Node* next{};
    Node* prev{};
    unordered_set<string>st;
    int val;
    
     Node(int va)
    {
        val = va;
    };
    
};
Node* head = new Node(-1);
Node* tail = new Node(INT_MAX);
unordered_map<string,Node*>mp;
    AllOne() {
        
        head->next =tail;
        tail->prev = head;
    }
    
    void add_node(Node* &prev, string key, int freq)
    {
       if(freq > prev->val)
       {
            if(freq == prev->next->val)
            {
                prev->next->st.insert(key);
                mp[key]=prev->next;
            }
            else
            {
                Node* after = prev->next;
                Node* node = new Node(freq);
                node->st.insert(key);
                prev->next = node;
                after->prev = node;
                node->next = after; node->prev= prev;
                mp[key]=node;
            }
       }
       else
       {
            prev->st.insert(key);
            mp[key]=prev;
       }
    }       
    void delete_next(Node* &prev)
    {
        Node* after = prev->next;
        Node* afterafter = after->next;
        prev->next = afterafter;
        afterafter->prev = prev;
    }
    void inc(string key) {
        if(mp.count(key) ==0)
        {
            add_node(head,key,1);
        }
        else
        {
            Node* node= mp[key];
            int freq= node->val;
            node->st.erase(key);
            if(node->st.empty())
            {
                Node* prev= node->prev;
                delete_next(prev);
                add_node(prev,key,freq+1);
            }
            else
            {
                add_node(node,key, freq+1);
            }
        }
    }
    
    void dec(string key) {
        Node* node = mp[key];
        if(node->val == 1)
        {
            node->st.erase(key);
            if(node->st.empty())
            {
                Node* prev = node->prev;
                delete_next(prev);
            }
            mp.erase(key);
        }
        else
        {
            node->st.erase(key);
            int freq = node->val;
            Node* prev = node->prev;
            if(node->st.empty())
            {
                delete_next(prev);
                add_node(prev,key,freq-1);
            }
            else
                add_node(prev,key,freq-1);
        }
    }
    
    string getMaxKey() {
        if(tail->prev == head)
            return "";
        return *(tail->prev->st.begin());
    }
    
    string getMinKey() {
        if(head->next == tail)
            return "";
            
        return *(head->next->st.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */