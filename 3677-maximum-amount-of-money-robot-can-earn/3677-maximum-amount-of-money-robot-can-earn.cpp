class Solution {
    
    int fn(int r, int c, vector<vector<int>>&coins, vector<vector<vector<int>>>&dp, int skippedCells)
    {
        if(r == coins.size()-1 && c == coins[0].size()-1)
        {
            if(coins[r][c]<0)
                if(skippedCells<2)
                    return 0;
            return coins[r][c];
        }
        auto &ret = dp[r][c][skippedCells];
        if(ret != INT_MIN)
            return ret;
        int c1 = INT_MIN;
        if(c+1< coins[0].size())
            c1 = coins[r][c]+fn(r,c+1,coins,dp,skippedCells);
        int c2 = INT_MIN;
        if(r+1<coins.size())
            c2 = coins[r][c]+fn(r+1,c,coins,dp,skippedCells);
        if(skippedCells<2)
        {
            if(c+1< coins[0].size() && coins[r][c] <0)
                c1 = max(c1,fn(r,c+1,coins,dp,skippedCells+1));
            if(r+1<coins.size() && coins[r][c]<0)
                c2 = max(c2, fn(r+1,c,coins,dp,skippedCells+1));
        }
        return ret = max(c1,c2);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>>(coins[0].size(),vector<int>(3,INT_MIN)));
        return fn(0,0,coins,dp,0);
        
    }
};