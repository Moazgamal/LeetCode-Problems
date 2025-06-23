class Solution {

    int countWays(int amount, int index, vector<int>& coins, vector<vector<int>>& dp) 
    {
        if (amount == 0) return 1;
        if (amount < 0 || index == coins.size())
            return 0;
        if (dp[amount][index] != -1) 
            return dp[amount][index];
        int take = countWays(amount - coins[index], index, coins, dp);
        int skip = countWays(amount, index + 1, coins, dp);
        return dp[amount][index] = take + skip;
    }

public:
    vector<int> findCoins(vector<int>& numWays) 
    {
        int n = numWays.size();
        vector<int> result;

        for (int i = 1; i <= n; ++i) 
        {
            vector<vector<int>> dp(i + 1, vector<int>(i-1 + 1, -1));
            int ways = countWays(i, 0, result, dp);

            if (numWays[i - 1] == 0) 
            {
                if (ways > 0) return {};
                continue;
            }

            if (ways > numWays[i - 1] || ways < numWays[i - 1] - 1) 
            {
                return {};
            } 
            else if (ways == numWays[i - 1] - 1) 
            {
                result.push_back(i);
            }
        }

        return result;
    }
};