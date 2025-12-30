class Solution {
    bool isvalid(int r, int c, int &rows, int &cols)
    {
        if(r<0 || r>=rows || c<0 || c>=cols)
            return false; 
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0; 
        if(grid.size() < 3 || grid[0].size() < 3)
            return 0; 
        int r = 1; 
        int c = 1; 
        int rows = grid.size(); int cols = grid[0].size();
        for(int r = 1; r< grid.size()-1; r++)
        {
            for(int c = 1; c< grid[0].size()-1; c++)
            {
                int up = grid[r-1][c]; int down = grid[r+1][c];
                int left = grid[r][c-1]; int right = grid[r][c+1];
                if(!isvalid(r-1,c,rows,cols)||!isvalid(r+1,c,rows,cols)||!isvalid(r,c-1,rows,cols)||!isvalid(r,c+1,rows,cols))
                    continue;
                vector<bool>v(10, false);
                int row = r-1; int col = c-1;
                int rr = row+3; int cc = col+3;
                bool can = true;
                for(; row< rr; row++)
                {
                    for(col=c-1; col<cc; col++)
                    {
                        if(grid[row][col]<1 || grid[row][col]>9||v[grid[row][col]])
                        {
                            can = false;
                            break;
                        }
                        else
                            v[grid[row][col]]=true;
                    }
                    if(!can)
                        break;
                }
                row = r-1; col = c-1;
                if(can)
                {
                    int sum1=grid[row][col]+grid[row][col+1]+grid[row][col+2];
                    int sum2 = grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2];
                    int sum3 = grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2];
                    int usum = sum1;
                    if(sum2 == usum && sum3 == usum)
                    {
                        int s1=grid[row][col]+grid[row+1][col]+grid[row+2][col];
                        int s2 = grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1];
                        int s3 = grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2];
                        if(s1 == usum && s2==usum && s3 ==usum)
                        {
                            int ss1= grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
                            int ss2 = grid[row+1][col+1]+grid[row+2][col]+grid[row][col+2];
                            if(ss1 == usum && ss2 == usum)
                                ans++;
                        }
                    }
                }
            }
        }
        return ans; 
        
    }
};