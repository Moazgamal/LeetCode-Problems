class NumMatrix {
public:
vector<vector<int>>v1;
vector<vector<int>>v2;
    NumMatrix(vector<vector<int>>& matrix) {
        v1= matrix; v2 = matrix;
        for(int c = 0; c< matrix[0].size(); c++)
        {
            int acc = 0; 
            for(int r= 0; r< matrix.size(); r++)
            {
                acc += matrix[r][c];
                v1[r][c] = acc;
            }
        }
        for(int r = 0; r< matrix.size(); r++)
        {
            int acc = 0; 
            for(int c = 0; c< matrix[0].size(); c++)
            {
                acc += v1[r][c]; 
                v2[r][c] = acc;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int val1 = 0; int val2 = 0; 
        if(col1 == 0)
            val2 = v2[row2][col2];
        else
            val2 = v2[row2][col2] - v2[row2][col1-1];
        
        if(row1 == 0)
            val1 = 0;
        else
        {
            if(col1 == 0)
                val1 = v2[row1-1][col2];
            else
                val1 = v2[row1-1][col2]-v2[row1-1][col1-1];
        }
            
        return val2-val1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */