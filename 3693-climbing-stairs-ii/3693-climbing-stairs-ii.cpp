class Solution {
    int fn(int stair, int n, vector<int>&costs, vector<int>&dp)
    {
        if(stair == n)
        {
            return 0; 
        }
        auto &ret = dp[stair];
        if(ret != INT_MAX/2)
            return ret; 
        int c1 = INT_MAX/4; int c2 = INT_MAX/4; int c3 = INT_MAX/4;
        if(stair+1 <= n)
            c1 = costs[stair]+ 1 + fn(stair+1, n, costs, dp);
        if(stair+2 <= n)
            c2 = costs[stair+1]+ 4 +fn(stair+2, n, costs, dp);
        if(stair+3 <=n)
            c3 = costs[stair+2]+ 9 +fn(stair+3, n, costs, dp);
        return ret = min(c1, min(c2, c3));
    }
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int>dp(n+2, INT_MAX/2);
        return fn(0, n, costs, dp);
        
    }
};