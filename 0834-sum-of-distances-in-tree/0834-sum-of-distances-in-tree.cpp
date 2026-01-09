class Solution {
    int dfs(int node, vector<vector<int>>&g, vector<int>&count, vector<int>&ans, vector<bool>&vis)
    {
        vis[node] = true; 
        count[node] = 1; 
        for(int i = 0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i]])
            {
                count[node] += dfs(g[node][i], g, count, ans, vis);
                ans[node] += (count[g[node][i]] + ans[g[node][i]]);
            }
        }
        return count[node];
    }
    void dfs2(int node, vector<vector<int>>&g, vector<int>&count, vector<int>&ans, vector<bool>&vis)
    {
        vis[node] = true; 
        for(int i = 0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i]])
            {
                ans[g[node][i]] += (ans[node]-count[g[node][i]]-ans[g[node][i]]); 
                ans[g[node][i]] += (count[0]- count[g[node][i]]);
                dfs2(g[node][i], g, count, ans, vis);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};

        vector<int>count(n,0);
        vector<int>ans(n,0);
        vector<vector<int>>graph(n);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0]; int to = edges[i][1];
            graph[from].push_back(to); graph[to].push_back(from);
        }
        vector<bool>vis(n, false); 
        dfs(0, graph, count, ans, vis);
        vector<bool>vis2(n, false); 
        dfs2(0, graph, count, ans, vis2); 
        return ans; 

    }
};