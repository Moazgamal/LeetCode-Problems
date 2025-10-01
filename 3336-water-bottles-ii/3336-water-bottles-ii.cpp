class Solution {
    int dp[201][201][201];
    int fn(int numBottles, int numExchange, int empty)
    {
        if(numBottles == 0)
        {
            if((empty < numExchange))
                return dp[numBottles][numExchange][empty]=0;
            return  dp[numBottles][numExchange][empty]= 
            fn(numBottles+1, numExchange+1, empty-numExchange);
        }
        auto &ret = dp[numBottles][numExchange][empty];
        if(ret != -1)
            return ret;
        int c1 = 0; 
        if(empty >= numExchange)
            c1 = fn(numBottles+1, numExchange+1, empty-numExchange);
        int c2 = 0; 
        for(int i = 1; i<= numBottles; i++)
        {
            c2 = max(c2, i+ fn(numBottles-i, numExchange, empty+i));
        }
        return dp[numBottles][numExchange][empty] = max(c1, c2);
    }
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        memset(dp, -1, sizeof(dp));
        int empty = 0; 
        return fn(numBottles, numExchange, empty);
    }
};