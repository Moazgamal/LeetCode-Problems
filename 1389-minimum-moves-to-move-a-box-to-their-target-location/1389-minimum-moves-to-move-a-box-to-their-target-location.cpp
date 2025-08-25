class Solution {
    int dr[4]= {0,0,-1,1};
        int dc[4]= {-1,1,0,0};
    bool isvalid(int r, int c, int &rows, int &cols)
    {
        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return false;
        return true;
    }
    bool canreach(int rbox, int cbox, int rperson, int cperson, 
    vector<vector<char>>&g, int ttarget, int ctarget)
    {
        if(rperson == ttarget && cperson== ctarget)
            return true; 
        queue<pair<int,int>>q;
        int rows = g.size(); int cols = g[0].size();
        q.push({rperson, cperson});
        vector<vector<bool>>vis(g.size(), vector<bool>(g[0].size(), false));
        vis[rbox][cbox]=true;
        vis[rperson][cperson]=true;
        while(!q.empty())
        {
            int sz = q.size(); 
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                
                int r = cur.first; int c = cur.second;
                if(cur.first == ttarget && cur.second == ctarget)
                    return true;
                for(int d = 0; d<4 ; d++)
                {
                    int row = r+dr[d]; int col = c+dc[d];
                    if(isvalid(row, col, rows, cols) && 
                    g[row][col] != '#' && !vis[row][col]
                    )
                    {
                        vis[row][col]=true;
                        q.push({row,col});
                    }
                }
            }
        }
        return false;
    }
public:
    int minPushBox(vector<vector<char>>& grid) {
        
        int x = grid.size()*grid[0].size();
        int rows = grid.size();
        queue<pair<int,int>>pq;
        bool s1 = false; bool s2 = false;
        int val1 = 0; int val2 = 0; 
        int cols = grid[0].size();
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 'S')
                {
                    s1 = true;
                    val1 = r*cols + c;  
                    grid[r][c] = '.';
                }
                if(grid[r][c] == 'B')
                {
                    s2 = true; 
                    val2 = r*cols + c; 
                    grid[r][c] = '.';
                }
                if(s1 && s2)
                    break;
            }
            if(s1 && s2)
                break;
        }
        pq.push({val1, val2});
        vector<vector<bool>> visited(x+1, vector<bool>(x+1,false)); // visited[person][box]
        visited[val1][val2] = true;
        int p = 0; 
        while(!pq.empty())
        {
            int sz = pq.size(); 
            while(sz--)
            {
                auto cur = pq.front(); pq.pop();
            int box = cur.second;
            int person = cur.first;
            int r = box/cols; int c = box%cols;
            int rp = person/cols; int cp = person%cols;
            if(grid[r][c] == 'T')
            {
                return p;
            }
            for(int d = 0; d< 4; d++)
            {
                int row = r+dr[d]; int col = c+dc[d];
                int tr = 0; int tc = 0;
                if(dr[d] == 0)
                {
                    if(dc[d] ==1)
                    {
                        tr = r; tc = c-1;
                    }
                    else
                    {
                        tr = r; tc = c+1;
                    }
                }
                if(dc[d] == 0)
                {
                    if(dr[d] == 1)
                    {
                        tr = r-1; tc = c;
                    }
                    else
                    {
                        tr = r+1; tc = c;
                    }
                }
                int bo = row*cols+ col;
                int per = r*cols + c;
                if(isvalid(row, col, rows, cols) && grid[row][col]!='#'
                && isvalid(tr, tc, rows, cols) && grid[tr][tc] != '#' )
                {
                    if(canreach(r, c, rp, cp, grid, tr, tc))
                    {
                        
                        if(!visited[per][bo])
                        {
                            visited[per][bo] = true;
                            pq.push({per,bo});
                        }
                    }
                }
            }
            }
            p++;
            
        }

        return -1; 
        
    }
};