class Solution {
    long long modPower(long long a, long long b, long long mod) {
    a %= mod;
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
    int height(int node, vector<vector<int>>&g, vector<bool>&vis)
    {
        vis[node] = true;
        int h = 0; 
        for(int i = 0; i< g[node].size(); i++)
            {
                if(!vis[g[node][i]])
                {
                    h = max(h, 1+height(g[node][i], g, vis));
                }
            }
        return h; 
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size()+2);
        for(int i = 0; i< edges.size(); i++)
            {
                int from = edges[i][0];
                int to = edges[i][1];
                graph[from].push_back(to);
                graph[to].push_back(from);
            }
        vector<bool>vis(edges.size()+2,false);
        int h = height(1,graph, vis);
        if(h==1)
            return 1;
        if(h==2)
            return 2;
        h = h-1;
        return modPower(2, h, 1e9+7);
    }
};