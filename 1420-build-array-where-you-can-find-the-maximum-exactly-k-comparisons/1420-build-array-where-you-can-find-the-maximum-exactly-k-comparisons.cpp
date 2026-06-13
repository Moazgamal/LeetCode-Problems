class Solution {
    const int MOD = 1e9+7;
    int dp[51][101][51];
    int fn(int idx, int prev_max, int k, int n, int m)
    {
        if(idx == n)
        {
            if(k == 0)
                return 1;
            return 0; 
        }
        auto &ret = dp[idx][prev_max][k];
        if(ret != -1)
            return ret ;
        ret = 0;
        for(int i = 1; i<= m; i++)
        {
            if(i > prev_max)
            {
                if(k ==0)
                    break;
                ret += fn(idx+1, i, k-1, n, m);
                ret %= MOD;
            }
            else
            {
                ret += fn(idx+1, prev_max, k, n, m);
                ret %= MOD;
            }
        }
        
        return ret; 
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return fn(0, 0, k, n, m);
        
    }
};