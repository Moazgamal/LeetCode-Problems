class CustomStack {
public:
vector<int> v;
int sz=0;
int cursize=0;
    CustomStack(int maxSize) {
        sz=maxSize;
        v.resize(maxSize);
    }
    
    void push(int x) {
        if(cursize == sz
        )
            return ;
        v[cursize]=x;
        cursize++;
        

    }
    
    int pop() {
        if(cursize==0)
            return -1;
        int x = v[cursize-1];
        cursize--;
        return x;
        
    }
    
    void increment(int k, int val) {

        if(cursize==0)
            return ;
        for(int i=0; i< k && i<cursize ; i++)
        {
            v[i] += val;
            cout<<v[i]<<"\n";
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */