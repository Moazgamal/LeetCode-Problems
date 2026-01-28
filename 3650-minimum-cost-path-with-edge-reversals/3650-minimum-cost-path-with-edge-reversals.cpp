class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>incoming(n);
        vector<vector<pair<int,int>>>outcoming(n);
        for(int i =0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int w = edges[i][2];
            incoming[to].push_back({from,w});
            outcoming[from].push_back({to,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int>dist(n, INT_MAX);
        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            if(cur.second == n-1)
                return cur.first;
            for(int i = 0;i< outcoming[cur.second].size(); i++)
            {
                int node = outcoming[cur.second][i].first;
                int w = outcoming[cur.second][i].second;
                if(dist[node] > w+cur.first)
                {
                    dist[node] = w+cur.first;
                    pq.push({w+cur.first, node});
                }
            }
            for(int i = 0; i< incoming[cur.second].size(); i++)
            {
                int node = incoming[cur.second][i].first;
                int w = incoming[cur.second][i].second;
                
                if(dist[node]>2*w+cur.first)
                {
                    dist[node] = 2*w+cur.first;
                    pq.push({2*w+cur.first, node});
                }
            }
        }
        return -1; 
        
    }
};