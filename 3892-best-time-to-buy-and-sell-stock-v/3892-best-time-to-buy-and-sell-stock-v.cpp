class Solution {
    long long fn(int idx, vector<int>&prices, int k , vector<std::vector<std::vector<long long>>>&dp, int s)
    {
        if(k ==0)
            return 0; 
        if(idx == prices.size())
        {
            if(k>=0 && s ==0)
                return 0; 
            return LONG_MIN/2;
        }
        auto &ret = dp[idx][k][s];
        if(ret != LONG_MIN)
            return ret;
        if(s == 0)
        {
            long long c1 = fn(idx+1, prices, k, dp, s);
            long long c2 = -prices[idx]+fn(idx+1, prices, k, dp, 1);
            long long c3 = prices[idx]+fn(idx+1, prices, k, dp, 2);
            return ret = max(c1, max(c2, c3));
        }
        else if(s==1)
        {
            long long c2 = LONG_MIN;
            
                c2 = prices[idx] + fn(idx+1,  prices, k-1,
                                                        dp,0);
            
            long long c3 = fn(idx+1,prices, k, dp, s);
            return ret = max(c3, c2);
        }
        else
        {
            long long c2 = LONG_MIN;
            
            c2 = -prices[idx] + fn(idx+1,  prices, k-1,
                                                        dp, 0);
            long long c3 = fn(idx+1,  prices, k, dp, s);
            return ret = max(c2, c3);
        }
    return ret ; 
        
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> dp(
    prices.size()+1, vector<vector<long long>>(
        k+1, vector<long long>(3, LONG_MIN)));

        return fn(0, prices, k, dp,0);
        
    }
};