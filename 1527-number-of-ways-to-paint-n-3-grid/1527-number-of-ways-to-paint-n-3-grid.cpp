const int MOD =1e9+7;
class Solution {
    int fn(int r, int c, vector<vector<int>> &dp, int cur_state, int prev_state, int n)
    {
        if(r == n)
            return 1; 
        if(c == 3)
            return fn(r+1, 0, dp, 0, cur_state,n);
        if(c == 0 && dp[r][prev_state] != -1)
            return dp[r][prev_state];
        
        int up = 0;
        if(r > 0)
        {
            up = (prev_state >> ((3-c-1)*2)) &3;
        }

        int prev = cur_state & 3;
        int ways = 0; 
        for(int color = 1; color<= 3; color++)
        {
            if(color == up || color == prev)
                continue;
            ways = (ways+fn(r, c+1, dp, (cur_state<<2) | color, prev_state, n))%MOD;
        }
        if(c == 0)
            dp[r][prev_state] = ways;
        return ways;
        
    }
public:
    int numOfWays(int n) {
        
        vector<vector<int>>dp(n, vector<int>(64,-1));
        return fn(0, 0,dp, 0, 0,n );
    }
};