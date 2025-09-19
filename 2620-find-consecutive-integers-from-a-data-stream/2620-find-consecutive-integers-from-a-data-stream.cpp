class DataStream {
public:
int last = 0; int cnt = 0; 
int val = 0; int _k = 0; 
    DataStream(int value, int k) {
        val = value; _k = k;
    }
    
    bool consec(int num) {
        if(num == val)
            cnt++;
        else
            cnt=0;
        return cnt >= _k ? true: false; 
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */