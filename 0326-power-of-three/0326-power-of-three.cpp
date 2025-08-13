class Solution {
public:
    bool isPowerOfThree(int n) {
        int x = 0; 
         if(n<0)
            return false; 
        if(n ==0)
            return false;
        
       while(n>0)
       {
            int rem = n%3;
            if(rem>1)
                return false; 
            if(rem >0)
            {
                x++; if(x>1) return false;
            }
            n/=3;
       }
       
       return true; 
    }
};