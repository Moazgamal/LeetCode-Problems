class Solution {
    int dr[4] = {0,0,-1,1};
    int dc[4]= {-1,1,0,0};
    bool isvalid(int r, int c, vector<vector<int>>&mat)
    {
        if(r<0 || c<0 || r>= mat.size() || c>= mat[0].size())
            return false;
        return true;
    }
    void dfs(int r, int c, vector<vector<int>>&matrix, int fr, int fc)
    {
        matrix[r][c]= 2;
        for(int d =0; d<4 ; d++)
        {
            if(dr[d]==fr && dc[d]==fc)
                continue;
            int row = r+dr[d];
            int col = c+dc[d];
            
            while(isvalid(row, col, matrix))
            {
                if(matrix[row][col]==0)
                    matrix[row][col]=3;
                else if(matrix[row][col]==1)
                {
                    dfs(row,col, matrix, -dr[d],-dc[d]);
                }
                else if(matrix[row][col]==2)
                    break;
                row += dr[d]; col += dc[d];
            }
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(int i = 0; i< walls.size(); i++)
        {
            int row = walls[i][0];
            int col = walls[i][1];
            matrix[row][col]=2;
        }
        for(int i = 0; i< guards.size(); i++)
        {
            int row = guards[i][0]; 
            int col = guards[i][1];
            matrix[row][col] = 1;
        }
        for(int r= 0; r< m; r++)
        {
            for(int c= 0; c< n; c++)
            {
                if(matrix[r][c]==1)
                    dfs(r,c,matrix,-1,-1);
            }
        }
        int ans =0 ;
        for(int r = 0; r<m; r++)
        {
            for(int c= 0 ; c< n; c++)
            {
                cout<<matrix[r][c]<<" ";
                if(matrix[r][c] ==0)
                    ans++;
            }
            cout<<"\n";
        }
        return ans;
        
    }
};