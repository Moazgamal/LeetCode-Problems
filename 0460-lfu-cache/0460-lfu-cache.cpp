class LFUCache {
public:
unordered_map<int,int> mp2;
unordered_map<int,int> mp3;
map<int, set<pair<int,int>> > mp;
unordered_map<int,int>count;
vector<int>v;
int i = 0; 
int sz = 0; 
int _capacity = 0;
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(mp2.count(key) > 0 && mp2[key]!=-1 )
        {
            v.push_back(key);
            int cnt = count[key];
            mp[cnt].erase({mp3[key],key});
            if(mp[cnt].empty())
                mp.erase(cnt);
            mp3[key] = v.size()-1;
            mp[cnt+1].insert({mp3[key],key});
            count[key]= cnt+1;
            return mp2[key];
        }
        return -1; 
        
    }
    
    void put(int key, int value) {
        if(mp2.count(key) >0 && mp2[key]!=-1)
        {
            mp2[key]=value;
            v.push_back(key);
            int cnt = count[key];
            mp[cnt].erase({mp3[key],key});
            if(mp[cnt].empty())
                mp.erase(cnt);
            mp3[key] = v.size()-1;
            mp[cnt+1].insert({mp3[key],key});
            count[key]= cnt+1;
            return ; 
        }
        if(sz < _capacity)
        {
            mp2[key]=value;
            v.push_back(key);
            mp3[key] = v.size()-1;
            sz++;
            count[key]=1;
            mp[1].insert({mp3[key],key});
            return; 
        }
        else
        {
            auto it = mp.begin();
            int freq = it->first;
            int si = it->second.size();
            
            auto _k = *(it->second.begin());
            int k = _k.second;
            mp2[k]=-1;
            int cnt = count[k];
            mp[cnt].erase({mp3[k],k});
            if(mp[cnt].empty())
                mp.erase(cnt);
            v.push_back(key);
            mp2[key]=value;
            mp3[key]=v.size()-1;
            mp[1].insert({mp3[key],key});
            count[key] = 1; 
            return; 
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */