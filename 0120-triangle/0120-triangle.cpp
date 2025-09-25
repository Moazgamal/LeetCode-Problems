class Solution {
    int fn(int r, int c, vector<vector<int>>&tr, vector<vector<int>>&dp)
    {
        if(r == tr.size())
            return 0; 
        auto &ret = dp[r][c];
        if(ret != INT_MAX)
            return ret; 
        for(int i = c ; i<= min(c+1, r); i++)
        {
            ret = min(ret, tr[r][i]+fn(r+1, i, tr, dp));
        }
        return ret; 
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        return fn(0, 0, triangle, dp);
        
        
    }
};