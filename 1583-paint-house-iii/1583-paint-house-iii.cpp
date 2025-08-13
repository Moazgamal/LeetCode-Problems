class Solution {
    int fn(int idx, vector<int>&houses, vector<vector<vector<int>>>&dp, vector<vector<int>>&cost
    , int m, int n, int target, int prevcolor)
    {
        if(target<0)
            return INT_MAX/2;
        if(idx >= houses.size())
        {
            if(target == 0)
                return 0; 
            return INT_MAX/2;
        }
        auto &ret = dp[idx][prevcolor][target];
        if(ret != INT_MAX)
            return ret; 
        
        if(houses[idx] == 0)
        {
            for(int i = 0; i< cost[idx].size(); i++)
            {
                int co = cost[idx][i];
                if(i+1 != prevcolor)
                    ret = min(ret, co+fn(idx+1, houses, dp, cost, m, n, target-1, i+1));
                else
                    ret = min(ret, co+fn(idx+1, houses, dp, cost, m, n, target, i+1));
            }
        }
        else
        {
            if(houses[idx] == prevcolor)
                ret = min(ret, fn(idx+1, houses, dp, cost, m, n, target, prevcolor));
            else
                ret = min(ret, fn(idx+1, houses, dp, cost, m, n, target-1, houses[idx]));
        }
        return ret; 
        
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(22, vector<int>(101, INT_MAX)));
        int ans=  fn(0, houses, dp, cost, m , n, target, 21);
        if(ans >= INT_MAX/2)
            return -1; 
        return ans; 
    }
};