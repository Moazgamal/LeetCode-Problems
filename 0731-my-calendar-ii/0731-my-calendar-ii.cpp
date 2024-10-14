class MyCalendarTwo {
public:
   map<int,int>v;
    MyCalendarTwo() {
        
        
    }
    
    bool book(int start, int end) {
        
            
        v[start]++;
        v[end]--;
        int prefixsum=0;
        for(auto x: v)
        {
            prefixsum+= x.second;
            if(prefixsum>2)
            {
                v[start]--;
                v[end]++;
                if(v[start]==0)
                    v.erase(start);
                if(v[end]==0)
                    v.erase(end);
                return false;
            }
            
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */