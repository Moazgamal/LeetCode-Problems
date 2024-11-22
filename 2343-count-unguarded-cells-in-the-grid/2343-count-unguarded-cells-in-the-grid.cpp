class Solution {
    int dr[4] = {0,0,-1,1};
    int dc[4]= {-1,1,0,0};
    char dir[4]={'u','d','l','r'};
    bool isvalid(int r, int c, vector<vector<int>>&mat)
    {
        if(r<0 || c<0 || r>= mat.size() || c>= mat[0].size())
            return false;
        return true;
    }
    
    void dfs(int r, int c, vector<vector<int>>&matrix, unordered_map<int, unordered_set<char>>&mp, int cnt)
    {
        matrix[r][c]= cnt;
        for(int d =0; d<4 ; d++)
        {
            int row = r+dr[d];
            int col = c+dc[d];
            int pos = c + (r*matrix[0].size());
            if(mp.count(pos)>0)
                {
                    if(mp[pos].find(dir[d]) != mp[pos].end())
                        continue;
                }
            while(isvalid(row, col, matrix) && matrix[row][col]!=2)
            {
                if(matrix[row][col]==0)
                    matrix[row][col]=3;
                else if(matrix[row][col]==1)
                {
                    int pox = col + (row*matrix[0].size());
                    char di= 'x';
                    if(dir[d]=='u')
                        di= 'd';
                    else if(dir[d] == 'd')
                        di = 'u';
                    else if(dir[d]=='l')
                        di= 'r';
                    else if(dir[d]=='r')
                        di = 'l';
                    mp[pox].insert(di);
                    dfs(row,col, matrix, mp, cnt);
                }
                else if(matrix[row][col] == cnt)
                {
                    int pos2 = col + (row*matrix[0].size());
                    char di= 'x';
                    if(dir[d]=='u')
                        di= 'd';
                    else if(dir[d] == 'd')
                        di = 'u';
                    else if(dir[d]=='l')
                        di= 'r';
                    else if(dir[d]=='r')
                        di = 'l';
                    mp[pos2].insert(di);
                    break;
                }
                else if(matrix[row][col]<cnt && matrix[row][col] != 3)
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
        unordered_map<int,unordered_set<char>>mp;
        int cnt = 4;
        for(int r= 0; r< m; r++)
        {
            for(int c= 0; c< n; c++)
            {
                if(matrix[r][c]==1)
                   {
                        dfs(r,c,matrix,mp,cnt);
                        cnt++;
                   }
                    
            }
        }
        int ans =0 ;
        
        for(int r = 0; r<m; r++)
        {
            for(int c= 0 ; c< n; c++)
            {
                if(matrix[r][c] ==0)
                    ans++;
            }
        }
        return ans;
        
    }
};