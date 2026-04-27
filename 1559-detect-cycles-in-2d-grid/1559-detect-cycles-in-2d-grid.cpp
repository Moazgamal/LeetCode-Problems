class Solution {
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    bool isvalid(int r, int c, vector<vector<char>>&g)
    {
        if(r<0||c<0||r>=g.size()|| c>=g[0].size())
            return false;
        return true;
    }
    bool dfs(int r, int c, vector<vector<char>>&g, int lastR, int lastC, vector<vector<bool>>&vis)
    {
        vis[r][c] = true; 
        for(int d = 0; d< 4; d++)
        {
            int row = r+dr[d];
            int col = c+dc[d];
            if(row == lastR && col == lastC)
                continue;
            if(!isvalid(row,col,g))
                continue;
            
            if(g[row][col] == g[r][c])
            {
                if(vis[row][col])
                    return true;
                vis[row][col] = true; 
                bool x = dfs(row, col, g, r, c, vis);
                if(x)
                    return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c= 0; c< grid[0].size(); c++)
            {
                if(!vis[r][c])
                {
                    if(dfs(r,c,grid,-1,-1,vis))
                        return true;
                }
            }
        }
        return false;
    }
};