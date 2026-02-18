class Solution {
    bool fn(int n)
    {
        int last = -1;
        while(n>0)
        {
            if(n%2 == 0)
            {
                if(last == -1)
                    last = 0;
                else if(last == 0)
                    return false; 
                last = n%2;
            }
            else
            {
                if(last == -1)
                    last = 1;
                else if(last == 1)
                    return false;
                last = n%2;
            }
            n /= 2;
        }
        return true; 
        
    }
public:
    bool hasAlternatingBits(int n) {
        return fn(n);
    }
};