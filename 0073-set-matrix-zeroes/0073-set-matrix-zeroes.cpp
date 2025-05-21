class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool FirstRow = false;
        bool FirstCol = false;
        for(int c = 0; c< matrix[0].size(); c++)
            if(matrix[0][c] == 0)
            {
                FirstRow = true; break; 
            }

        for(int r = 0; r< matrix.size(); r++)
            if(matrix[r][0] == 0)
            {
                FirstCol = true; break; 
            }


        for(int r = 0; r< matrix.size(); r++)
        {
            for(int c = 0; c< matrix[0].size(); c++)
            {
                if(matrix[r][c] ==0)
                {
                    matrix[0][c] = 0; 
                    matrix[r][0] = 0; 
                }
            }
        }
        
        for(int c = 1; c< matrix[0].size(); c++)
        {
            if(matrix[0][c] ==0)
            {
                for(int x = 1; x< matrix.size(); x++)
                {
                    matrix[x][c] = 0; 
                }
            }
        }

        for(int r = 1; r< matrix.size(); r++)
        {
            if(matrix[r][0] ==0)
            {
                for(int x = 1; x< matrix[0].size(); x++)
                {
                    matrix[r][x] = 0; 
                }
            }
        }

        if(FirstRow)
        {
            for(int c = 0; c< matrix[0].size(); c++)
                matrix[0][c] = 0; 
        }
        if(FirstCol)
        {
            for(int r = 0; r< matrix.size(); r++)
                matrix[r][0]  = 0;
        }
    }
};