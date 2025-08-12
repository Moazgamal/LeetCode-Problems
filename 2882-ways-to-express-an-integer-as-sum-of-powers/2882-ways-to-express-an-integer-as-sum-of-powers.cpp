class Solution {
    const int MOD= 1e9+7;
    int dp[301][301];
    int fn(int sum, int p, int cur)
    {
        if(sum ==0)
        {
            return 1; 
        }
        auto &ret = dp[sum][cur];
        if(ret != -1)
            return ret;
        int ans = 0; 
        for(int i = cur; i<= sum; i++)
        {
            long long num = pow(i,p);
            if(num<=sum)
            {
                ans+= fn(sum-num, p, i+1);
                ans %= MOD;
            }
        }
        return  dp[sum][cur] = ans; 
    }
    
public:
    int numberOfWays(int n, int x) {
        // vector<vector<int>>dp(301, vector<int>(301, -1));
        memset(dp, -1, sizeof(dp));
        return fn(n, x, 1)%MOD ;
        
    }
};