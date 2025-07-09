class Solution {
    void dfs(int node, vector<vector<pair<int,int>>>&g, vector<bool> &vis, int mid)
    {
        vis[node] = true;
        for(int i = 0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i].first] && g[node][i].second > mid)
            {
                dfs(g[node][i].first, g, vis, mid);
            }
        }
    }
    int fn(int mid , vector<vector<pair<int,int>>> &g)
    {
        int n = g.size(); 
        vector<bool>vis(n, false);
        int ans = 0; 
        for(int i = 0; i< n; i++)
        {
            if(!vis[i])
            {
                ans++; dfs(i, g, vis, mid);
            }
        }

        return ans; 
    }
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<vector<pair<int,int>>>graph(n);
        for(int i = 0;i< edges.size(); i++)
        {
            mini = min(edges[i][2], mini);
            maxi = max(edges[i][2], maxi);
            int from = edges[i][0]; int to = edges[i][1];
            int time = edges[i][2];
            graph[from].push_back({to, time});
            graph[to].push_back({from, time});
        }
        if(fn(0, graph)>=k)
            return 0 ;
        int start = mini; int end = maxi;
        int mid = -1; int pos = -1; 
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(fn(mid, graph) >=k)
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return pos;

        
    }
};  