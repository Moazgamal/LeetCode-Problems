class Solution {
    bool isvalid(int r, int c, vector<vector<int>>& grid)
    {
        if(r<0 || c<0 || r>=grid.size() || c>= grid[0].size())
            return false;
        return true; 
        
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        bool x = false;
        bool y = false;
        queue<pair<int, pair<int,int>>>q;
        
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c =0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 0)
                    x = true;
                else
                {
                    y = true;
                    q.push({0, {r,c}});
                }
            }
        }
        if(!x || !y)
            return -1; 
        int ans = INT_MIN;
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), false));
        int dr[4] = {0,0,-1,1};
        int dc[4]= {-1,1,0,0};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur =q.front();q.pop();
                int r = cur.second.first;
                int c = cur.second.second;
                int dis = cur.first;
                for(int d = 0; d< 4; d++)
                {
                    int row = r+dr[d]; int col = c+dc[d];
                    if(isvalid(row,col, grid) && !vis[row][col] && grid[row][col] ==0)
                    {
                        ans = max(ans, 1+dis);
                        q.push({1+dis,{row,col}});
                        vis[row][col] = true;
                    }
                }

            }
        }
        return ans;
        
        
    }
};