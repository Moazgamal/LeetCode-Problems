class Trie {
public:
    const static int MAX_CHAR= 26;
    Trie* arr[MAX_CHAR] {};
    bool isleaf {};
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(int i = 0; i< word.size(); i++)
        {
            int idx = word[i]-'a';
            if(!cur->arr[idx])
                cur->arr[idx] = new Trie();
            cur = cur->arr[idx];
        }
        cur->isleaf= true;
        
        
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(int i = 0; i< word.size(); i++)
        {
            int idx = word[i]-'a';
            if(!cur->arr[idx])
                return false;
            cur = cur->arr[idx];
        }
       if(cur->isleaf)
        return true;
        return false;
        
        
    }
    
    bool startsWith(string prefix) {
        
        Trie* cur = this;
        for(int i = 0; i< prefix.size(); i++)
        {
            int idx = prefix[i]-'a';
            if(!cur->arr[idx])
                return false;
            cur = cur->arr[idx];
        }return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */