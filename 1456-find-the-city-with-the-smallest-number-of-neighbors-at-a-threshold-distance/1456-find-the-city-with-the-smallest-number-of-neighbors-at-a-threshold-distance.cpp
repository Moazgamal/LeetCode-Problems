class Solution {
    void BFS(int node, vector<vector<pair<int,int>>> &graph, int th, vector<vector<int>> &v)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node});
        vector<int> dist(graph.size(), 1e9);
        dist[node]=0;
        for(int level = 0, sz = pq.size(); !pq.empty(); sz = pq.size())
        {
            while(sz--)
            {
                auto cur = pq.top(); pq.pop();
                for(int i = 0; i< graph[cur.second].size(); i++)
                {
                    int newnode = graph[cur.second][i].first;
                    int w = graph[cur.second][i].second;
                    if(dist[newnode] > cur.first+w)
                    {
                        dist[newnode] = cur.first+w;
                        pq.push({dist[newnode],newnode});
                    }
                }
            }
        }
        for(int i = 0; i< dist.size(); i++)
        {
            if(i==node)
                continue;
            if(dist[i] <= th)
                v[node].push_back(i);
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i= 0; i< edges.size(); i++)
        {
            int from = edges[i][0]; int to = edges[i][1];
            int w = edges[i][2];
            graph[from].push_back({to, w}); graph[to].push_back({from,w});
        }
        vector<vector<int>> v(n);
        for(int i = 0; i< n ; i++)
        {
            BFS(i, graph, distanceThreshold,v);
        }
        vector<int> ans;
        int maxi = INT_MAX; 
        for(int i=0; i< v.size(); i++)
        {
            if(v[i].size()<maxi)
            {
                maxi = v[i].size();
            }
        }
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i].size()== maxi)
            {
                ans.push_back(i);
            }
        }
        sort(ans.rbegin(), ans.rend());
        return ans[0]; 
        
    }
};