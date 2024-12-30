class Solution {
    int dp[100001];
    int MOD = 1000000007;
    int fn(int x , int low , int high, int one, int zero)
    {
        if(x>high)
            return 0; 
        auto &ret = dp[x];
        if(ret != -1)
            return ret;
        if(x >= low )
            return ret = 1 + fn(x+zero, low, high,one,zero)%MOD+fn(x+one, low, high, one,zero)%MOD;
        return ret = fn(x+zero, low, high, one, zero)%MOD+fn(x+one,low, high,  one,zero)%MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0; 
        memset(dp,-1,sizeof(dp));
        ans += fn(zero, low, high, one,zero);   
        ans%=MOD;
        ans+=fn(one,low, high,  one,zero);
        return ans%MOD;
        
    }
};