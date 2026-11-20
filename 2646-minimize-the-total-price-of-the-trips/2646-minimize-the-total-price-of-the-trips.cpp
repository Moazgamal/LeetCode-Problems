class Solution {
    bool Dfs(int from, int to, vector<vector<int>>&g, vector<int>&vis, int parent)
    {
        if(from == to)
        {
            vis[from]++;
            return true;
        }
        for(int i = 0; i< g[from].size(); i++)
        {
            if(g[from][i] != parent && Dfs(g[from][i], to, g, vis, from))
            {
                vis[from]++;
                return true;
            }
        }
        return false;
    }
    int Traverse(int cur, vector<vector<int>>&g, vector<int>&vis, bool canHalve, 
    vector<int>&price, vector<vector<int>>&Dp, int parent, vector<bool>&NewVis)
    {
        auto &ret = Dp[cur][canHalve];

        if(ret != INT_MAX)
            return ret; 
        
        int c1 = 0; 
        NewVis[cur] = false;
        if(canHalve)
            c1 = ( (price[cur]/2*vis[cur]) );
        
        int c2 = (price[cur]*vis[cur]);
        
        for(int i = 0; i< g[cur].size(); i++)
        {
            if(vis[g[cur][i]] > 0 && g[cur][i] != parent)
            {
                if(canHalve)
                    c1 += Traverse(g[cur][i], g, vis, false, price, Dp, cur, NewVis);
                c2 += Traverse(g[cur][i], g, vis, true, price, Dp, cur, NewVis);
            }
        }
        if(canHalve)
            c2 = min(c2, c1);
        ret = min(ret, c2);
        return ret; 
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

        vector<int>vis(n, 0);
        vector<bool>NewVis(n, true);
        vector<vector<int>>graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(int i = 0; i< trips.size(); i++)
        {
            int from = trips[i][0];
            int to = trips[i][1];
            Dfs(from, to, graph, vis, -1);
        }
        int ans = 0; 
        vector<vector<int>>Dp(n, vector<int>(2, INT_MAX));
        for(int i = 0; i< vis.size(); i++)
        {
            if(vis[i] >0 && NewVis[i]==true)
                ans += Traverse(i, graph, vis, true, price, Dp, i, NewVis);
        }
        return ans; 
    }
};