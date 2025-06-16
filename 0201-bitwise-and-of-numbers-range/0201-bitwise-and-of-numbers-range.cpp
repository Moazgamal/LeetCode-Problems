class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0; 
        for(int i = 31; i>=0; i--)
        {
            int x = (1<<i);
            
            if(((right&x) == x) && ((left&x) !=x))
                return cnt; 
            if(((left&x)==x) && ((right&x) !=x))
                return cnt; 
            if(((right&x) ==x) && ((left&x)==x))
                cnt += (x);
        }
        return cnt; 
        
    }
};