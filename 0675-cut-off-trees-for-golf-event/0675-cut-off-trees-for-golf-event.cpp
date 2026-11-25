class Solution {
    int Dr[4] = {0,0,-1,1};
    int Dc[4] = {-1,1,0,0};
    int fn(int curSourceRow, int curSourceCol, int curDestRow, int curDestCol, 
    vector<vector<int>>&forest)
    {
        int steps = 0; 
        vector<vector<bool>>vis(forest.size(), vector<bool>(forest[0].size(), false));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{curSourceRow, curSourceCol}});
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                if(cur.second.first == curDestRow && cur.second.second == curDestCol)
                    return cur.first;
                vis[cur.second.first][cur.second.second] = true;
                for(int D = 0; D < 4; D++)
                {
                    int row = cur.second.first+Dr[D];
                    int col = cur.second.second+Dc[D]; 
                    if(row>=0 && row<forest.size() && col>=0 && col<forest[0].size()
                    && forest[row][col]!=0 && vis[row][col] == false)
                    {
                        q.push({cur.first+1, {row,col}});
                        vis[row][col]=true;
                    }
                }
            }
        }
        return -1; 
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {

        map<int,pair<int,int>>mp;
        for(int r = 0; r< forest.size(); r++)
        {
            for(int c = 0; c< forest[0].size(); c++)
            {
                if(forest[r][c] != 0 && forest[r][c] != 1)
                    mp[forest[r][c]] = make_pair(r,c);
            }
        }
        if(mp.size() == 0)
            return 0; 
        int curSourceRow = 0; int curSourceCol = 0; int steps = 0; 
        for(auto &j : mp)
        {
            int curDestRow = j.second.first; int curDestCol = j.second.second; 
            auto x = fn(curSourceRow, curSourceCol, curDestRow, curDestCol, forest);
            if(x == -1)
                return -1; 
            curSourceRow = curDestRow;
            curSourceCol = curDestCol;
            steps += x;
        }
        return steps;
    }
};