class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()==1)
            return mat[0];
        // once go right ,,, if not right go down,  
        // second once go down ,,, if no down go right,
        // done    
        bool Flip = false;
        vector<int> res;
        int rows = mat.size(); int cols = mat[0].size();
        int startCol = 0; 
        for(int r = 0; r< mat.size(); r++)
        {
            int row = 0; int c = 0; 
            
            row = r; c = 0; 
            int i = res.size();
            while(row >= 0 && row<mat.size() && c>=0 && c< mat[0].size())
            {
                res.push_back(mat[row][c]);
                
                row--; c++;
            }
            if(Flip)
            {
                int sz = res.size();
                reverse(res.begin()+i, res.begin()+sz);
            }
            Flip = !Flip;
        }
        for(int c = 1; c< cols; c++)
        {
           
           int  r = rows-1; int col = c; 
            int i = res.size();
            while(r >= 0 && r<mat.size() && col>=0 && col< mat[0].size())
            {
                res.push_back(mat[r][col]);
                
                r--; col++;
                
            }
            if(Flip)
            {
                int sz = res.size();
                reverse(res.begin()+i, res.begin()+sz);
            }
            Flip= !Flip;
        }
        return res;

        
    }
};