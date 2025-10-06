class Solution {
    bool isvalid(int r, int c, int rows, int cols)
    {
        if(r < 0 || c<0 || r>= rows || c >= cols)
            return false; 
        return true; 
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int dr[4]= {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int rows  = heights.size(); 
        int cols = heights[0].size();
        // vector<vector<bool>>v1(heights.size(), vector<int>(heights[0].size(), false));
        // vector<vector<bool>>v2(heights.size(), vector<int>(heights[0].size(), false));
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        vector<vector<bool>>vis1(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>>vis2(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>>ans;
        for(int c = 0; c< heights[0].size(); c++)
        {
            // v1[0][c]= true;
            // v2[heights.size()-1][c] = true; 
            q1.push({0,c});
            q2.push({heights.size()-1, c});
            vis1[0][c]= true; 
            vis2[heights.size()-1][c] = true; 
        }
        for(int r = 1; r< heights.size(); r++)
        {
            // v1[r][0]= true;
            q1.push({r,0});
            vis1[r][0]= true; 
        }
        for(int r = 0; r< heights.size()-1; r++)
        {
            // v2[r][heights[0].size()-1] = true; 
            q2.push({r, heights[0].size()-1});
            vis2[r][heights[0].size()-1] = true; 
        }
        while(!q1.empty())
        {
            auto cur = q1.front(); 
            q1.pop();
            for(int d = 0; d< 4; d++)
            {
                int row = cur.first + dr[d];
                int col = cur.second + dc[d];
                if(isvalid(row, col, rows, cols) && !vis1[row][col] && heights[row][col]>= heights[cur.first][cur.second])
                {
                    vis1[row][col]= true;
                    q1.push({row, col});
                }
            }
        }
        while(!q2.empty())
        {
            auto cur = q2.front(); 
            q2.pop();
            for(int d = 0; d< 4; d++)
            {
                int row = cur.first + dr[d];
                int col = cur.second + dc[d];
                if(isvalid(row, col, rows, cols) && !vis2[row][col] && heights[row][col]>= heights[cur.first][cur.second])
                {
                    vis2[row][col]= true;
                    q2.push({row, col});
                }
            }
        }

        for(int i = 0; i< vis2.size(); i++)
        {
            for(int j = 0; j< vis2[i].size(); j++)
            {
                if(vis1[i][j] == true && vis2[i][j] == true)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans; 


        
    }
};