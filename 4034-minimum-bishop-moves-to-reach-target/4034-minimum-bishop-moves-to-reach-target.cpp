class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        
        int Dr[4] = {-1, -1, 1, 1};
        int Dc[4] = {1 , -1, -1, 1};
        queue<pair<pair<int,int>, int>>q;
        q.push({{source[0]-1, source[1]-1}, 0});
        vector<vector<bool>>vis(8, vector<bool>(8, false));
        vis[source[1]-1][source[0]-1]=true;
        int rTarget = target[0]-1;
        int cTarget = target[1]-1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                int r = cur.first.first; int c = cur.first.second;
                if(r>rTarget)
                {
                    if(c>cTarget)
                    {
                        if(r-rTarget == c-cTarget)
                            return cur.second+1;
                    }
                    else
                    {
                        if(r-rTarget == cTarget-c)
                            return cur.second+1;
                    }
                }
                else
                {
                    if(rTarget-r == c-cTarget)
                        return cur.second+1;
                    else
                    {
                        if(rTarget-r == cTarget -c)
                            return cur.second+1;
                    }
                }
                if(cur.first.first == target[0]-1 &&
                cur.first.second == target[1]-1)
                    return cur.second;
                for(int D = 0; D<4; D++)
                {
                    int row = cur.first.first + Dr[D];
                    int col = cur.first.second + Dc[D];
                    while(row >=0 && row< 8 && col>=0 && col< 8 && !vis[row][col])
                    {
                        q.push({{row,col}, cur.second+1});
                        vis[row][col] = true;
                        row+=Dr[D];
                        col+=Dc[D];
                    }
                }
            }
        }
        return -1;
    }
};