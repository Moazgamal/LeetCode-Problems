class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        int i = 0; 
        while(true)
            {
                ans += (1<<i);
                i++;
                if(ans>=n)
                        return ans;
            }
        return ans; 
        
    }
};