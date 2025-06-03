class Solution {
    int fn(int idx, vector<vector<int>>&dp, vector<vector<int>>&freqs, int rows, int forb,
    int cols)
    {
        if(idx == cols)
            return 0; 
        auto &ret = dp[idx][forb];
        if(ret != -1)
            return ret; 
        ret = INT_MAX;
        for(int i = 0; i <=9; i++)
        {
            if(i == forb)
                continue;
            int freq = freqs[idx][i];
            ret = min(ret, (rows-freq) + fn(idx+1, dp, freqs, rows, i,cols));
        }
        return ret; 
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {

        vector<vector<int>>dp(grid[0].size(), vector<int>(11,-1));

        vector<vector<int>> v(grid[0].size(), vector<int>(11,0));
        
        for(int c = 0; c< grid[0].size(); c++)
        {
            for(int r= 0; r< grid.size(); r++)
            {
                v[c][grid[r][c]]++;
            }
        }
        return fn(0,dp,v,grid.size(),10,grid[0].size());





        
    }
};