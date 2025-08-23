class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int minrow = INT_MAX;
        int mincol = INT_MAX;
        int maxrow = INT_MIN;
        int maxcol = INT_MIN;
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    minrow =min(minrow, r); mincol = min(mincol, c);
                    maxrow = max(maxrow, r); maxcol = max(maxcol, c);
                }
            }
        }
        return (maxrow-minrow+1)*(maxcol-mincol+1);
        
    }
};