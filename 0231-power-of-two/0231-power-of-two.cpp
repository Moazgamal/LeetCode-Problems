class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x = 0; 
        if(n<0)
            return false; 
        if(n ==0)
            return false; 
        for(int i = 0; i< 32; i++)
        {
            if((n&(1<<i)) >0)
            {
                x++; if(x>1) return false;
            }
        }
        return true;
        
    }
};