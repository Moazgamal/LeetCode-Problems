class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0; 

        while(true)
        {
            if(target == 1)
                return ans; 
            if(target %2 != 0)
            {
                target--; ans++;
            }
            else
            {
                if(maxDoubles > 0)
                {
                    ans++; target = (target>>1); maxDoubles--;
                }
                else
                {
                    ans += (target-1); 
                    return ans; 
                }
            }
        }
        return ans; 
        
    }
};