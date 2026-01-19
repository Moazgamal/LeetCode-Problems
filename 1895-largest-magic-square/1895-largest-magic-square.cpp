class Solution {
    void calc(int rowStart, int rowEnd, int colStart, int colEnd,
     vector<vector<int>>&prefixRows, vector<vector<int>>&prefixCols, int &ans,
     vector<vector<int>>&diag1, vector<vector<int>>&diag2)
    {
        
        int temp = -1; 
        bool status = true;
        for(int r = rowStart; r<= rowEnd; r++)
        {
            if(temp == -1)
            {
                if(colStart == 0)
                    temp = prefixRows[r][colEnd];
                else
                    temp  = prefixRows[r][colEnd]-prefixRows[r][colStart-1];
            }
            else
            {
                int sum = 0;
                if(colStart == 0)
                    sum = prefixRows[r][colEnd];
                else
                    sum  = prefixRows[r][colEnd]-prefixRows[r][colStart-1];
                if(temp != sum)
                {
                    status = false;
                    break;
                }
            }
        }
        int orgSum = temp;
        
        if(status)
        {
            for(int c = colStart; c<= colEnd; c++)
            {
                int sum = 0; 
                if(rowStart == 0)
                    sum = prefixCols[rowEnd][c];
                else
                    sum = prefixCols[rowEnd][c]-prefixCols[rowStart-1][c];
                if(sum != orgSum)
                {
                    status = false;
                    break;
                }
                
            }
        }
        if(status)
        {
            int sum1 = 0; int sum2 = 0; 
            if(rowStart  == 0 || colStart == 0)
                sum1 = diag1[rowEnd][colEnd];
            else
                sum1 = diag1[rowEnd][colEnd]-diag1[rowStart-1][colStart-1];

            if(rowEnd == diag1.size()-1 || colStart == 0)
                sum2 = diag2[rowStart][colEnd];
            else
                sum2 = diag2[rowStart][colEnd]-diag2[rowEnd+1][colStart-1];
            
            if(sum1 != orgSum || sum2 != orgSum)
                status = false; 
        }
        if(status)
            ans = max(ans, (rowEnd-rowStart)+1);
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1; 
        vector<vector<int>>prefixRows(grid.size(), vector<int>(grid[0].size(),0));
        vector<vector<int>>prefixCols(grid.size(), vector<int>(grid[0].size(),0));
        vector<vector<int>>diag1(grid.size(), vector<int>(grid[0].size(),0));
        vector<vector<int>>diag2(grid.size(), vector<int>(grid[0].size(),0));
        for(int r = 0; r< grid.size(); r++)
        {
            int sum = 0; 
            for(int c=  0; c< grid[0].size(); c++)
            {
                sum+=grid[r][c];
                prefixRows[r][c] = sum;
            }
        }
        for(int c = 0; c< grid[0].size(); c++)
        {
            int sum = 0; 
            for(int r= 0; r< grid.size(); r++)
            {
                sum+= grid[r][c];
                prefixCols[r][c]= sum;
            }
        }
        // diag1
        for(int c = 0; c< grid[0].size(); c++)
        {
            int i = 0; int j = c;
            int sum = 0;
            while(i< grid.size() && j < grid[0].size())
            {
                sum+= grid[i][j];
                diag1[i][j] = sum;
                i++; j++;
            }
        }
        for(int r = 0; r< grid.size(); r++)
        {
            int i = r; int j = 0;
            int sum = 0;
            while(i< grid.size() && j < grid[0].size())
            {
                sum+= grid[i][j];
                diag1[i][j] = sum;
                i++; j++;
            }
        }
        //diag2
        for(int c = 0; c<grid[0].size(); c++)
        {
            int i = grid.size()-1; int j = c;
            int sum = 0;
            while(i>=0 && j < grid[0].size())
            {
                sum+= grid[i][j];
                diag2[i][j] = sum;
                i--; j++;
            }
        }
        for(int r = grid.size()-1; r>=0; r--)
        {
            int i = r; int j = 0;
            int sum = 0;
            while(i>=0 && j < grid[0].size())
            {
                sum+= grid[i][j];
                diag2[i][j] = sum;
                i--; j++;
            }
        }

        /////////////////////////////////////
        
        for(int i  = 0; i< grid.size(); i++)
        {
            for(int j = 0; j< grid[0].size(); j++)
            {
                int r = i; int c = j; 
                while(c<grid[0].size() && r< grid.size())
                {
                    calc(i, r, j, c, prefixRows, prefixCols, ans, diag1, diag2);
                    r++; c++;
                }
            }
        }
        return ans; 
    }
};