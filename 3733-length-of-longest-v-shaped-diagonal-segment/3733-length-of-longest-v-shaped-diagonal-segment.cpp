class Solution {
    bool isvalid(int r, int c, int rows, int cols)
    {
        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return false;
        return true; 
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        int curRow = 0; int curCol = 0;
        int rows = grid.size(); int cols = grid[0].size();
        vector<vector<int>>g1(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>g2(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>g3(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>>g4(grid.size(), vector<int>(grid[0].size()));
        int loops = rows+cols-1;
        int loops2 = loops; 
        while(loops2--)
        {
            int val1 = 0; 
            int r = curRow; int c = curCol;
            while(isvalid(r, c, rows, cols))
            {
                if(grid[r][c] == 1)
                {
                    g1[r][c] = 1;
                    r--; 
                    c++; continue;
                }
                g1[r][c] = 1;
                int prev = grid[r][c];
                r--;
                c++;
                int cnt = 1; 
                while(isvalid(r, c, rows, cols))
                {
                    if(grid[r][c] == 1)
                    {
                        g1[r][c] = 1; r--; c++; cnt = 0; continue;
                    }
                    if(grid[r][c] == prev)
                    {
                        g1[r][c] = 1; cnt = 1; r--; c++;
                    }
                    else
                    {
                        g1[r][c] = ++cnt;
                        prev = grid[r][c];
                        r--;
                        c++;
                    }
                }
            }
            if(curRow == rows-1 && curCol == 0)
            {
                curCol++;
            }
            else if(curRow == rows-1)
                curCol++;
            else
                curRow++;
        }

        loops2 = loops; curRow = rows-1; curCol = cols-1;
        while(loops2--)
        {
            int r = curRow; int c = curCol;
            while(isvalid(r, c, rows, cols))
            {
                if(grid[r][c] == 1)
                {
                    g2[r][c] = 1;
                    r++; 
                    c--; continue;
                }
                g2[r][c] = max(g2[r][c], 1);
                int prev = grid[r][c];
                r++;
                c--;
                int cnt = 1; 
                while(isvalid(r, c, rows, cols))
                {
                    if(grid[r][c] == 1)
                    {
                        g2[r][c] = 1; r++; c--; cnt = 0; continue;
                    }
                    if(grid[r][c] == prev)
                    {
                        g2[r][c] = max(g2[r][c], 1); cnt = 1; r++; c--;
                    }
                    else
                    {
                        g2[r][c] = max(g2[r][c], ++cnt);
                        prev = grid[r][c];
                        r++;
                        c--;
                    }
                }
            }
            if(curRow == 0 && curCol == cols-1)
            {
                curCol--;
            }
            else if(curRow == 0)
                curCol--;
            else
                curRow--;
        }

        loops2= loops;

        curRow = 0; curCol = cols-1;

        while(loops2--)
        {
            int r = curRow; int c = curCol;
            while(isvalid(r, c, rows, cols))
            {
                if(grid[r][c] == 1)
                {
                    g3[r][c] = 1;
                    r++; 
                    c++; continue;
                }
                g3[r][c] = max(g3[r][c], 1);
                int prev = grid[r][c];
                r++;
                c++;
                int cnt = 1; 
                while(isvalid(r, c, rows, cols))
                {
                    if(grid[r][c] == 1)
                    {
                        g3[r][c] = 1; r++; c++; cnt = 0; continue;
                    }
                    if(grid[r][c] == prev)
                    {
                        g3[r][c] = 1; cnt = 1; r++; c++;
                    }
                    else
                    {
                        g3[r][c] = ++cnt;
                        prev = grid[r][c];
                        r++;
                        c++;
                    }
                }
            }
            
            if(curRow == 0 && curCol == 0)
            {
                curRow++;
            }
            else if(curCol == 0)
                curRow++;
            else
                curCol--;
        }

        loops2= loops;

        curRow = rows-1; curCol = 0;

        while(loops2--)
        {
            int val1 = 0; 
            int r = curRow; int c = curCol;
            while(isvalid(r, c, rows, cols))
            {
                if(grid[r][c] == 1)
                {
                    g4[r][c] = 1;
                    r--; 
                    c--; continue;
                }
                g4[r][c] = max(g4[r][c], 1);
                int prev = grid[r][c];
                r--;
                c--;
                int cnt = 1; 
                while(isvalid(r, c, rows, cols))
                {
                    if(grid[r][c] == 1)
                    {
                        g4[r][c] = max(g4[r][c], 1); r--; c--; cnt = 0; continue;
                    }
                    if(grid[r][c] == prev)
                    {
                        g4[r][c] = max(g4[r][c], 1); cnt = 1; r--; c--;
                    }
                    else
                    {
                        g4[r][c] = max(g4[r][c], ++cnt);
                        prev = grid[r][c];
                        r--;
                        c--;
                    }
                }
            }
            
            if(curRow == rows-1 && curCol == cols-1)
            {
                curRow--;
            }
            else if(curCol == cols-1)
                curRow--;
            else
                curCol++;
        }

        int ans = 0; 

        for(int r = 0; r < grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    ans = max(ans, 1);
                    int h = 1; 
                    int row = r+1; int col = c+1; int x = 2; 
                    while(isvalid(row, col, rows, cols) && grid[row][col] != 1 
                    && grid[row][col] == x)
                    {
                        ans = max(ans, h+g1[row][col]);
                        h++; row++; col++;
                        x = x == 2 ? 0 : 2;
                    }
                    h = 1; row = r+1; col = c-1; x = 2; 
                    while(isvalid(row, col, rows, cols) && grid[row][col] != 1 
                    && grid[row][col] == x)
                    {
                        ans = max(ans, h+g3[row][col]);
                        h++; row++; col--;
                        x = x == 2 ? 0 : 2;
                    }
                    h = 1; row = r-1; col = c+1; x = 2; 
                    while(isvalid(row, col, rows, cols) && grid[row][col] != 1 
                    && grid[row][col] == x)
                    {
                        ans = max(ans, h+g4[row][col]);
                        h++; row--; col++;
                        x = x == 2 ? 0 : 2;
                    }
                    h = 1; row = r-1; col = c-1; x = 2; 
                    while(isvalid(row, col, rows, cols) && grid[row][col] != 1 
                    && grid[row][col] == x)
                    {
                        ans = max(ans, h+g2[row][col]);
                        h++; row--; col--;
                        x = x == 2 ? 0 : 2;
                    }
                }
            }
        }
        return ans; 

    }
};