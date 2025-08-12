class Solution {
    long long dp[10001][8][8];
    const int MOD = 1e9+7;
    long long fn(int idx, int last, int prevlast, int &n)
    {
        if(idx == n)
            return 1;
        auto ret = dp[idx][last][prevlast];
        if(ret != -1)
            return ret; 
        long long ans = 0; 
        for(int i = 1; i<= 6; i++)
        {
            if(last == 2 && i == 4 || last == 4 && i==2
        || last == 3 && i == 6 || last == 6 && i == 3|| last == 4 && i == 6
        || last == 6 && i == 4 || last == 2 && i == 4 || last == 4 && i == 2
        ||last == 6 && i == 2 || last == 2 && i == 6)
            {
                continue;
            }
            if(last == i || prevlast == i)
                continue;
            ans += fn(idx+1, i, last, n);
            ans %= MOD;
        }
        return dp[idx][last][prevlast] = ans; 
    }
public:
    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        return fn(0, 7,7, n);

        
    }
};