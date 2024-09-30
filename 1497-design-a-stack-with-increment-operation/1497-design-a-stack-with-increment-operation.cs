public class CustomStack {
    public int[] v;
public int sz=0;
public int cursize=0;

    public CustomStack(int maxSize) {
        v = new int[maxSize];
        sz=maxSize;
    }
    
    public void Push(int x) {
        if(cursize == sz)
            return ;
        v[cursize]=x;
        cursize++;
    }
    
    public int Pop() {
        if(cursize==0)
            return -1;
        int x = v[cursize-1];
        cursize--;
        return x;
        
    }
    
    public void Increment(int k, int val) {
         if(cursize==0)
            return ;
        for(int i=0; i< k && i<cursize ; i++)
        {
            v[i] += val;
        }
        
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * obj.Increment(k,val);
 */