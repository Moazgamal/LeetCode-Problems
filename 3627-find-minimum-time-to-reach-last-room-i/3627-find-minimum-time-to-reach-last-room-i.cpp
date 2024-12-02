class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(moveTime.size(), vector<int>(moveTime[0].size(),INT_MAX));
        dist[0][0]=0;
        int dr[4] = { -1, 1, 0, 0};
        int dc[4] = {0,0, -1, 1};
        for(int sz = pq.size(); !pq.empty(); sz = pq.size())
        {
            while(sz--)
            {
                auto cur = pq.top(); pq.pop();
                if(cur.second.first == moveTime.size()-1 && cur.second.second == moveTime[0].size()-1)
                    return cur.first;
                for(int d = 0; d<4; d++)
                {
                    int row = cur.second.first+dr[d];
                    int col = cur.second.second+dc[d];
                    if(row<0 || col<0 || row>=moveTime.size() || col>= moveTime[0].size())
                        continue;
                    int t = cur.first;
                    if(moveTime[row][col] > t)
                    {
                        t = moveTime[row][col]+1;
                    }
                    else
                        t++;
                    if(dist[row][col] > t)
                    {
                        dist[row][col]  = t;
                        pq.push({dist[row][col], {row,col}});
                    }
                }
            }
        }
        return 0;
        
    }
};