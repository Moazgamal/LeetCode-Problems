class Solution {
    bool isvalid(int r, int c, vector<vector<int>>&grid)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size())
            return false;
        return true;
    }
    int fn(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        auto &ret  = dp[r][c];
        if(ret != -1)
            return ret;
        if(isvalid(r-1,c+1,grid) && grid[r-1][c+1] > grid[r][c])
            ret = max(ret, 1+fn(r-1,c+1,grid,dp));
        if(isvalid(r,c+1,grid) && grid[r][c+1] > grid[r][c])
            ret = max(ret, 1+fn(r, c+1, grid,dp));
        if(isvalid(r+1,c+1,grid) && grid[r+1][c+1] > grid[r][c])
            ret = max(ret , 1+fn(r+1, c+1, grid,dp));
        if(ret ==-1)
            return 0;
        return ret;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        for(int r=0; r< grid.size(); r++)
        {
            ans = max(ans, fn(r,0,grid,dp) );
        }return ans;
    }
};