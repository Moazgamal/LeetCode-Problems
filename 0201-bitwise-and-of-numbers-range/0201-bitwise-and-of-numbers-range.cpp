class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left ==0)
            return 0; 
            int idx1 = -1;
            int idx2 = -1;
        for(int i = 31; i>=0; i--)
        {
            int x = (1<<i);
            if(((right&x)==x) && idx1 == -1)
                idx1 = i;
            if(((left&x) == x) && idx2 == -1)
            {
                idx2= i;
            }
        }
        if(idx1-idx2>=1)
            return 0; 
        
        int cnt = 0; 
        bool st= false;
        for(int i = 31; i>=0; i--)
        {
            int x = (1<<i);
            if(((right&x)==x) && st == false)
            {
                st = true;
                if((left&x) == x)
                {
                    cnt+= (x);
                }
            }
            else if(st == true)
            {
                if(((right&x) == x) && ((left&x) !=x))
                    return cnt; 
                if(((left&x)==x) && ((right&x) !=x))
                    return cnt; 
                if(((right&x) ==x) && ((left&x)==x))
                    cnt += (x);
            }
           
        }
        return cnt; 
        
    }
};