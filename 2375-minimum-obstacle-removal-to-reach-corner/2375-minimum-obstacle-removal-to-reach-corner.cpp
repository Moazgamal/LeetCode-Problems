class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        // let's go with Dijkstra Alogorithm to find the shortest Path 
        queue<pair<int,pair<int,int>>>q;
        int dr[4]={-1,1,0,0};
        int dc[4]= {0,0,-1,1};
        q.push({0,{0,0}});
        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(),1e9));
        dist[0][0] = 0;
        
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                pair<int,pair<int,int>> p = q.front(); q.pop();
                for(int d =0; d<4; d++)
                {
                    
                    int row = p.second.first; 
                    int col = p.second.second;
                    int row2 = row+dr[d]; int col2 = col+dc[d];
                    if(row2<0 || col2<0 || row2>=grid.size() || col2>=grid[0].size())
                        continue;
                    int newval = dist[row][col]+grid[row2][col2];
                    if(newval < dist[row2][col2])
                    {
                        dist[row2][col2] = newval;
                        q.push({dist[row2][col2],{row2,col2}});
                    }
                }

            }
        }
        return dist[grid.size()-1][grid[0].size()-1];
        
    }
};