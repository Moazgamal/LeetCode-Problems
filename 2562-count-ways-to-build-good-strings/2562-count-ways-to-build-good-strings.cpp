class Solution {
    int MOD = 1000000007;
    int fn(int x , int low , int high, vector<int>&dp,int one, int zero)
    {
        if(x>high)
            return 0; 
        auto &ret = dp[x];
        if(ret != -1)
            return ret;
        if(x >= low )
            return ret = 1 + fn(x+zero, low, high, dp,one,zero)%MOD+fn(x+one, low, high, dp,one,zero)%MOD;
        return ret = fn(x+zero, low, high, dp,one, zero)%MOD+fn(x+one,low, high, dp, one,zero)%MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0; 
        vector<int>dp(high+1,-1);
        ans += fn(zero, low, high, dp,one,zero);   
        ans%=MOD;
        ans+=fn(one,low, high, dp, one,zero);
        return ans%MOD;
        
    }
};