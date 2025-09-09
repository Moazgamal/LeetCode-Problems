class Solution {
    static const int MAX = 2001;  
    int dp[MAX][MAX];
    const int MOD = 1e9 + 7;

    int fn(int start, int end, int n, int delay, int forget) {
       
        if (dp[start][end] != -1) return dp[start][end];

        long long ways = 0;
        if (end > n) ways = 1;

        int f = min(end, n+1);

        for (int t = start; t < f; ++t) 
        {
            ways = (ways + fn(t + delay, t + forget, n, delay, forget)) % MOD;
        }

        dp[start][end] = (int)ways;
        return dp[start][end];
    }

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp, -1, sizeof(dp));

        return fn(1 + delay, 1 + forget, n, delay, forget);
    }
};
