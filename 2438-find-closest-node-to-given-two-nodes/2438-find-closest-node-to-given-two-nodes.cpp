class Solution {
    void dfs(int node, vector<vector<int>> &graph, unordered_map<int,int>&mp, vector<bool>&vis, int steps, int &p)
    {
        vis[node]  = true;
        
        mp[node] = steps; 
        for(int i = 0; i< graph[node].size(); i++)
        {
            if(!vis[graph[node][i]])
            {
                dfs(graph[node][i], graph , mp, vis, steps+1, p); 
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> graph(edges.size());
        for(int i = 0; i< edges.size(); i++)
        {
            int to = edges[i];
            if(to!=-1)
                graph[i].push_back(to);
        }
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        vector<bool> vis(edges.size(), false);
        int steps = 0; 
        dfs(node1, graph, mp1, vis, steps, node1);
        vector<bool> vis2(edges.size(), false);
        steps = 0; 
        dfs(node2, graph, mp2, vis2, steps, node2);
        if(mp1.size() ==0 || mp2.size() ==0)
            return -1; 
        int ans = INT_MAX;
        int node = INT_MAX;
        for(auto x: mp1)
        {
            if(mp2.count(x.first) !=0)
            {
                int dis1 = x.second;
                int dis2 = mp2[x.first];
                int maxi = max(dis1, dis2);
                if(maxi == ans)
                {
                    node = min(node, x.first);
                }
                else if(maxi < ans)
                {
                    ans = maxi; node = x.first;
                }

            }
        }
        if(node == INT_MAX)
            return -1; 
        return node;


    }
};