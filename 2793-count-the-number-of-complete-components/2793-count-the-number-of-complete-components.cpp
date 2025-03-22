class Solution {
    void dfs(int node, unordered_set<int>&nodes, vector<vector<int>>&g, vector<bool>&vis)
    {
        vis[node] = true;
        nodes.insert(node);
        for(int i =0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i]])
            {
                nodes.insert(g[node][i]);
                dfs(g[node][i], nodes, g, vis);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vector<bool> vis(n,false);
        int ans = 0; 
        for(int i =0; i< n; i++)
        {
            if(!vis[i])
            {
                unordered_set<int> nodes;
                dfs(i, nodes, graph,vis);
                bool y = true;
                for(auto x : nodes)
                {
                    if(graph[x].size() != nodes.size()-1)
                    {
                        y = false;
                        break;
                    }
                    for(int i = 0; i< graph[x].size(); i++)
                    {
                        if(nodes.find(graph[x][i]) == nodes.end())
                        {
                            y = false;
                            break;
                        }
                    }
                    if(!y)
                        break;
                }
                if(y)
                    ans++;
            }
        }
        return ans;
        
    }
};