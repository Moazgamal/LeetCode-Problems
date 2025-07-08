class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0,0});
        vector<int> dist(n,INT_MAX);
        int ans = -1; 
         vector<vector<pair<int,pair<int,int>>>> graph(n);
         for(int i = 0; i< edges.size(); i++)
         {
            int from = edges[i][0];
            int to = edges[i][1];
            int start = edges[i][2];
            int end = edges[i][3];
            graph[from].push_back({to,{start,end}});
         }
        while(!q.empty())
        {
            auto cur = q.top();
            q.pop();

            if(cur.second == n-1)
                return cur.first;

            int time = cur.first;
            
            for(int i = 0; i< graph[cur.second].size(); i++)
            {
                int node = graph[cur.second][i].first;
                int start = graph[cur.second][i].second.first;
                int end = graph[cur.second][i].second.second;

                if(time > end)
                    continue;
               
                if(time >=start && time<=end )
                {
                    if(dist[node] > time+1)
                    {
                        dist[node] = time+1; 
                        q.push({time+1, node});
                    }
                }
                else
                {
                    if(dist[node] > start+1 )
                    {
                        dist[node] = start+1;
                        q.push({start+1, node});
                    }
                }
            }
        }
        return -1; 
    }
};