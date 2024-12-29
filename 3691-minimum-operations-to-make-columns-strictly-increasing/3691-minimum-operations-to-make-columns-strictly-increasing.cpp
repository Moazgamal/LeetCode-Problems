class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0; 
        for(int c=0; c< grid[0].size(); c++)
            {
                int maxi = -1;
                for(int r = 0; r< grid.size(); r++)
                    {
                        if(grid[r][c] > maxi)
                            maxi = grid[r][c];
                        else
                        {
                            ans += (maxi-grid[r][c] +1);
                            maxi++;
                        }
                    }
            }
        return ans;
        
    }
};