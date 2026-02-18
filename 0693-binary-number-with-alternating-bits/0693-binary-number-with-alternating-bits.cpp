class Solution {
    bool fn(int n)
    {
        int last = n%2; n/=2;
        while(n>0)
        {
            if(n%2 == 0)
            {
                if(last == 0)
                    return false; 
                last = 0;
            }
            else
            {
                if(last == 1)
                    return false;
                last = 1;
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