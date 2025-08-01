class Solution {
    bool isvalid(int r, int c, vector<vector<int>>&g)
    {
        if(r<0 || c<0 || r>= g.size() || c>= g[0].size())
            return false;
        return true;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0, {0,0}});
        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(),INT_MAX));

        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            int cost = cur.first; int row = cur.second.first;
            int col = cur.second.second;
            if(row == grid.size()-1 && col == grid[0].size()-1)
                return cost;
            
            int dir = grid[row][col];
            int newRow = row; int newCol = col;
            if(dir == 1)
                newCol++;
            else if(dir == 2)
                newCol--;
            else if(dir==3)
                newRow++;
            else
                newRow--;
            if(isvalid(newRow, newCol, grid))
            {
                if(dist[newRow][newCol] > cost)
                {
                    dist[newRow][newCol] = cost;
                    pq.push({cost, {newRow, newCol}});
                }
            }
            for(int i = 0; i<4; i++)
            {
                int r = row+dr[i]; int c = col+dc[i];
                if(r == newRow && c == newCol)
                    continue;
                if(isvalid(r, c, grid))
                {
                    if(dist[r][c] > cost+1)
                    {
                        dist[r][c] = cost+1;
                        pq.push({cost+1, {r, c}});
                    }
                }
            }
        }
        return 0; 
    }
};