class Solution {
    bool isvalid(int r, int c, int rows, int cols)
    {
        if(r<0||c<0 || r>=rows|| c>= cols)
            return false;
        return true; 
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({grid[0][0], {0,0}});
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int rows = grid.size(); int cols = grid[0].size();
    vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    while(!pq.empty())
    {
        auto cur = pq.top(); 
        pq.pop();
        int r = cur.second.first; int c = cur.second.second;
        int time = cur.first;
        if(r == grid.size()-1 && c == grid[0].size()-1)
            return time;
        for(int d = 0; d< 4; d++)
        {
            int row = r+dr[d]; 
            int col = c+dc[d];
            if(isvalid(row, col, rows, cols) )
            {
                int maxi = max(time , grid[row][col]);
                if(dist[row][col] > maxi)
                {
                    dist[row][col] = maxi;
                    pq.push({maxi, {row, col}});
                }
            }
        }
    }
    return 0; 
        
    }
};