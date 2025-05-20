class Solution {
    bool isvalid(int r, int c, vector<string> &m)
    {
        if(r<0 || c<0 || r>= m.size() || c>= m[0].size())
            return false;
        return true;
    }
public:
    int minMoves(vector<string>& matrix) {
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        unordered_map<string, vector<pair<int,int>>> mp;

        for(int i = 0; i< matrix.size(); i++)
        {
            for(int j = 0; j< matrix[0].size(); j++)
            {
                string s = "";
                 s.push_back(matrix[i][j]);
                mp[s].push_back({i,j});
            }
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist (matrix.size(), vector<int>(matrix[0].size(), INT_MAX/2));
        q.push({0,{0,0}});
        dist[0][0] = 0;
int ans = INT_MAX/2;
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.top();
                q.pop();
                if(cur.second.first == matrix.size()-1 &&
                cur.second.second == matrix[0].size()-1)
                {
                    return cur.first;
                }
                if(dist[cur.second.first][cur.second.second] > cur.first)
                    continue;
                string s = "";
                s.push_back(matrix[cur.second.first][cur.second.second]);
                if(s>="A" && s<="Z" && mp.count(s) !=0 && s!="." && s!="#")
                {
                    for(auto x: mp[s])
                    {

                        int row = x.first; int col = x.second;
                        if(row == cur.second.first && col == cur.second.second)
                            continue;
                        if(dist[row][col] > cur.first)
                        {
                            dist[row][col] = cur.first;
                            q.push({cur.first,{row,col}});
                        }
                    }
                    mp.erase(s);

                }
                for(int d = 0; d< 4; d++)
                {
                    int r = cur.second.first + dr[d];
                    int c= cur.second.second + dc[d];
                    if(isvalid(r,c,matrix) &&  dist[r][c]>cur.first+1 && matrix[r][c] != '#')
                    {
                        dist[r][c] = cur.first+1;
                        q.push({cur.first+1,{r,c}});
                    }
                }
            }
        }
        if(ans == INT_MAX/2)
            return -1;
        return ans; 
        
    }
};