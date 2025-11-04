class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {

        for(int r = 0; r< grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(r == c  || r+c == grid.size()-1)
                {
                    if(grid[r][c] ==0)
                        return false;
                    continue;
                }
                if(grid[r][c] != 0)
                    return false;
            }
        }return true;

        
    }
};