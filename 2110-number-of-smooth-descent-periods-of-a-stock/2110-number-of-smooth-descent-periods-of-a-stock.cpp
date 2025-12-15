class Solution {
    long long fn(int idx, vector<int>&prices, vector<int>&dp)
    {
        auto &ret = dp[idx];
        if(ret != -1)
            return ret; 
        ret = 1; 
        if(idx+1 < prices.size() && prices[idx+1] == prices[idx]-1)
            ret += fn(idx+1, prices, dp);
        return ret; 
    }
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        vector<int>dp(prices.size(), -1);
        for(int i = 0; i< prices.size(); i++)
            ans += fn(i, prices, dp);
        return ans; 
    }
};