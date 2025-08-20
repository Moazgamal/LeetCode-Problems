class Solution {
    bool isvalid(int r, int c, vector<vector<int>>&g)
    {
        if(r<0 || c<0 || r>= g.size() || c>= g[0].size())
            return false;
        return true;
    }
    int fn1(int r, int c, vector<vector<int>>&g, vector<vector<int>>&dp)
    {
        if(!isvalid(r, c, g) || g[r][c] == 0)
            return 0; 
        auto &ret = dp[r][c];
        if(ret != -1)
            return ret; 
        int c1 = fn1(r+1, c, g, dp);
        int c2 = fn1(r+1, c+1, g, dp);
        int c3 = fn1(r+1, c-1, g, dp);
        return ret = 1 + min(c1, min(c2, c3));
    }
    int fn2(int r, int c, vector<vector<int>>&g, vector<vector<int>>&dp)
    {
        if(!isvalid(r, c, g) || g[r][c] == 0)
            return 0; 
        auto &ret = dp[r][c];
        if(ret != -1)
            return ret; 
        int c1 = fn2(r-1, c, g, dp);
        int c2 = fn2(r-1, c+1, g, dp);
        int c3 = fn2(r-1, c-1, g, dp);
        return ret = 1 + min(c1, min(c2, c3));
    }
public:
    int countPyramids(vector<vector<int>>& grid) {
        vector<vector<int>>dp1(grid.size(), vector<int>(grid[0].size(),-1));
        vector<vector<int>>dp2(grid.size(), vector<int>(grid[0].size(),-1));
        int ans = 0; 
        for(int r =0; r< grid.size()-1; r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    if(dp1[r][c] == -1)
                    {
                        ans += fn1(r,c, grid, dp1)-1;

                    }
                    else
                        ans+= dp1[r][c]-1;
                }
            }
        }
        for(int r =grid.size()-1; r>0; r--)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    if(dp2[r][c] == -1)
                    {
                        ans += fn2(r,c, grid, dp2)-1;
                    }
                    else
                        ans+= dp2[r][c]-1;
                }
            }
        }
        return ans; 
        
    }
};