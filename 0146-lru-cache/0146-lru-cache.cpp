class LRUCache {
public:
unordered_map<int,int> mp2;
unordered_map<int,int> mp3;
vector<int>v;
int i = 0; 
int _capacity = 0; 
    LRUCache(int capacity) {
        _capacity = capacity;
        i=0;
    }
    
    int get(int key) {
        if(mp2.count(key) > 0)
        {
            v.push_back(key);
            mp3[key] = v.size()-1;
            return mp2[key];
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(mp2.size() < _capacity)
        {
            if(mp2.count(key) > 0)
            {
                mp2[key]=value;
                v.push_back(key);
                mp3[key] = v.size()-1;
            }
            else
            {
                mp2[key]=value;
                v.push_back(key);
                mp3[key] = v.size()-1;
            }
        }
        else
        {
            if(mp2.count(key) > 0)
            {
                mp2[key]=value;
                v.push_back(key);
                mp3[key]=v.size()-1;
            }
            else
            {
                int j = i; 
                for(; j< v.size(); j++)
                {
                    if(mp2.count(v[j])>0&& mp3[v[j]] == j)
                    {
                        mp2.erase(v[j]);
                        // mp3.erase(v[j]);
                        v.push_back(key);
                        mp3[key]=v.size()-1;
                        mp2[key]=value;
                        break;
                    }
                }
                i= j+1;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */