class Solution {
    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1, 1, 0, 0};
    bool isvalid(int r, int c, vector<vector<int>>&result)
    {
        if(r<0 || r>= result.size() || c<0 || c>= result[0].size())
            return false;
        return true;
        
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> result(isWater.size(), vector<int>(isWater[0].size(),-1));
        queue<pair<int,int>> q;
        for(int r = 0; r < isWater.size(); r++)
        {
            for(int c = 0; c< isWater[0].size(); c++)
            {
                if(isWater[r][c] == 1)
                {
                    result[r][c] = 0; 
                    q.push({r,c});
                }
            }
        }
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto p = q.front(); 
                q.pop();
                for(int d = 0; d<4; d++)
                {
                    int row = p.first + dr[d];
                    int col = p.second + dc[d];
                    if(!isvalid(row,col,result))
                        continue;
                    if(result[row][col] == -1)
                    {
                        result[row][col] = result[p.first][p.second]+1;
                        q.push({row,col});
                    }
                }
            }
        }
        return result;
        
    }
};