public class MyCalendar 
{
    public List<Tuple<int,int>> list;

    public MyCalendar() 
    {
        list = new List<Tuple<int,int>>();
    }

    public int BS(int value)
    {
        int start = 0; int end= list.Count-1;
        int pos = -1;int mid = -1;
        while(start <= end)
        {
            mid= start + (end-start)/2;
            if(list[mid].Item1 == value)
                return mid;
            else if(list[mid].Item1 > value)
            {
                pos=mid;
                end = mid-1;
            }
            else
                start = mid + 1;
        }
        return pos;
    }
    
    public void shift_right(int indx)
    {
        Tuple<int,int> temp = list[indx];
        for(int i=indx+1; i<= list.Count-1; i++)
        {
            Tuple<int,int> temp2= list[i];
            list[i]=temp;
            temp=temp2;
            
        }
        list.Add(temp);
    }

    public bool Book(int start, int end) 
    {

        if(list.Count==0)
        {
            list.Add(new Tuple<int,int>(start,end));
            return true;
        }
        int indx = BS(start);
        if(indx == -1)
        {
            int sz = list.Count-1;
            if(start < list[sz].Item2)
                return false;
            list.Add(new Tuple<int,int>(start,end));
            return true;
        }
        if(list[indx].Item1 == start)
            return false;
        if(list[indx].Item1 < end)
            return false;
        if(indx-1 >=0)
        {
            if(list[indx-1].Item2> start)
            {
                return false;
            }
        }
        shift_right(indx);
        list[indx]=new Tuple<int,int>(start,end);
        return true;
   
        
        
    }
}



/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.Book(start,end);
 */