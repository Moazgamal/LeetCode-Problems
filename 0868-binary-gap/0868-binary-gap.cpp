class Solution {
    void fn(int &n, int &ans)
    {
        int cnt = -1; 
        while(n >0)
        {
            if(n % 2 == 1)
            {
                if(cnt == -1)
                    cnt = 0; 
                else
                {
                    ans = max(ans, cnt+1); cnt=0;
                }
            }
            else
            {
                if(cnt != -1)
                    cnt++;
            }
            n /= 2; 
        }
    }
public:
    int binaryGap(int n) {
        int ans = 0; 
        fn(n, ans);
        return ans; 
        
    }
};