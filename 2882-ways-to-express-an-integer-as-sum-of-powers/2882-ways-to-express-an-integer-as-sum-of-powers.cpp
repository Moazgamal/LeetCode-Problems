class Solution {
    const int MOD= 1e9+7;
    int dp[301][301];
    int roots[301][6]; // roots[num][n]

void precomputeRoots() {
    for (int num = 1; num <= 300; num++) {
        for (int n = 1; n <= 5; n++) {
            roots[num][n] = (int)round(pow(num, 1.0 / n));
        }
    }
}

inline int getRoot(int num, int n) {
    return roots[num][n];
}
    inline long long fastPowSmall(int base, int exp) {
    switch (exp) {
        case 1: return base;
        case 2: return base * base;
        case 3: return base * base * base;
        case 4: {
            long long sq = base * base;
            return sq * sq;
        }
        case 5: {
            long long sq = base * base;
            return sq * sq * base;
        }
        default: return 1; // shouldn't happen
    }
}
    
    int fn(int sum, int p, int cur)
    {
        if(sum ==0)
        {
            return 1; 
        }
        auto ret = dp[sum][cur];
        if(ret != -1)
            return ret;
        int ans = 0; 
        int ro = sum;

        
        ro = ceil(getRoot(sum,p));
        
        for(int i = cur; i<= ro; i++)
        {
            long long num = fastPowSmall(i,p);
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
        precomputeRoots();
        memset(dp, -1, sizeof(dp));
        return fn(n, x, 1) ;
        
    }
};