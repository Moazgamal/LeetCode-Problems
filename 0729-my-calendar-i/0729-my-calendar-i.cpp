class MyCalendar {
public:
vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    int BS(int value)
    {
        int start = 0; int end= v.size()-1;
        int pos = -1;int mid = -1;
        while(start <= end)
        {
            mid= start + (end-start)/2;
            if(v[mid].first == value)
                return mid;
            else if(v[mid].first > value)
            {
                pos=mid;
                end = mid-1;
            }
            else
                start = mid + 1;
        }
        return pos;
    }
    void shift_right(int indx)
    {
        pair<int,int> temp = v[indx];
        for(int i=indx+1; i<= v.size()-1; i++)
        {
            pair<int,int> temp2= v[i];
            v[i]=temp;
            temp=temp2;
            
        }
        v.push_back(temp);
    }
    bool book(int start, int end) {
        if(v.size()==0)
        {
            v.push_back({start,end});
            return true;
        }
        int indx = BS(start);
        if(indx == -1)
        {
            int sz = v.size()-1;
            if(start < v[sz].second)
                return false;
            v.push_back({start,end});
            return true;
        }
        if(v[indx].first == start)
            return false;
        if(v[indx].first < end)
            return false;
        if(indx-1 >=0)
        {
            if(v[indx-1].second> start)
            {
                return false;
            }
        }
        shift_right(indx);
        v[indx]={start,end};
        return true;
        

        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */