public class MyCalendarTwo {
SortedDictionary<int,int> v;
    public MyCalendarTwo() {
         v = new SortedDictionary<int,int>();
        
    }
    
    public bool Book(int start, int end) {
        if(v.ContainsKey(start))
            v[start]++;
        else
            v.Add(start,1);
        if(v.ContainsKey(end))
            v[end]--;
        else
            v.Add(end,-1);
        
        int prefixsum=0;
        foreach(var x in v)
        {
            prefixsum+= x.Value;
            if(prefixsum>2)
            {
                v[start]--;
                v[end]++;
                if(v[start]==0)
                    v.Remove(start);
                if(v[end]==0)
                    v.Remove(end);
                return false;
            }
            
        }
        return true;
        
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.Book(start,end);
 */