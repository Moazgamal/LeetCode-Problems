class Solution {
    int dr[4] = {0,0,-1,1};
    int dc[4]= {-1,1,0,0};
    bool isvalid(int r, int c, vector<vector<int>>&grid)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size())
            return false;
        return true;
    }
    bool fn(int r , int c, vector<vector<int>>&grid, int health
    ,vector<vector<vector<int> > > &dp)
    {
        
        if(r== grid.size()-1  && c== grid[0].size()-1)
        {
            if(grid[r][c] ==0)
                return true;
            else if(health>=2)
            {
                return true;
            }
            return false;
        }
        auto&ret = dp[r][c][health];
        if(ret !=-1)
            return ret;
        if(health<1)
            return ret = false;
        int x =grid[r][c];
        grid[r][c]=-1; 
        for(int d=0; d<4; d++)
        {
            int row = r+dr[d];
            int col = c+dc[d];
            if(isvalid(row,col, grid) && grid[row][col]!=-1)
            {
                if(x ==0 )
                {
                    if(fn(row,col, grid,health,dp))
                        return ret = true;
                }
                else 
                {
                    if(health>=2)
                    {
                        if(fn(row,col,grid,health-1,dp))
                            return ret = true;
                    }
                }
            }
        }
        grid[r][c]=x;
        return ret = false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        vector<vector<vector<int> > > dp(
        grid.size(), vector<vector<int> >(grid[0].size(), vector<int>(health+1,-1)));
        
        return fn(0,0,grid,health,dp);
        
    }
};