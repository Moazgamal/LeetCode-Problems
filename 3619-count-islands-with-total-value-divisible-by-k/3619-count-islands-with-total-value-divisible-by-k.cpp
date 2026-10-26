class Solution {
    int Dr[4]= {-1, 1, 0,0};
    int Dc[4] = {0,0,-1,1};
    void Dfs(int r, int c, vector<vector<int>>&g, int &k, long long &sum)
    {
        sum += g[r][c];
        g[r][c] = -1;
        for(int D = 0; D<4; D++)
        {
            int row = r+Dr[D];
            int col = c+Dc[D];
            if(r+Dr[D] >= 0 && r+Dr[D] < g.size()
            && c+Dc[D] >=0 && c+Dc[D] < g[0].size()
            && g[row][col] != -1 && g[row][col] != 0)
            {
                Dfs(row, col, g, k, sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
int ans = 0; 
        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c < grid[0].size(); c++)
            {
                if(grid[r][c] != -1 && grid[r][c] != 0)
                {
                    long long sum = 0; 
                    Dfs(r,c,grid,k,sum);
                    if(sum%k==0)
                        ans++;
                }
            }
        }
        return ans;
    }
};