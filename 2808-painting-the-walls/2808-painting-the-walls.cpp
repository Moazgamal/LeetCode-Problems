class Solution {
    int fn(int idx, vector<int>&cost, vector<int>&time,
    vector<vector<int>>&dp, int cur)
    {
        if(cur <=0)
            return 0; 
        if(idx == cost.size())
        {
            return INT_MAX/2;
        }

            
            auto &ret = dp[idx][cur];
            
            if(ret != 0)
                return ret;
        long long pick = cost[idx]+fn(idx+1, cost, time, dp, cur-time[idx]-1);
        
        
        long long leave = fn(idx+1, cost, time, dp, cur); 
        return ret =  min(pick, leave);
        
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(501, vector<int>(501,0));
        int collectedE =0; 
        int collectedT = 0;  int TT = 0 ;
        return fn(0, cost, time, dp, cost.size());
        
    }
};