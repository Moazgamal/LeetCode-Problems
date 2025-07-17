class Solution {
    void dfs(int node, vector<vector<pair<int,int>>>&g,vector<bool>&vis, int mid)
    {
        vis[node]= true;
        for(int i = 0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i].first] && g[node][i].second <= mid)
            {
                
                dfs(g[node][i].first, g,vis, mid);
            }
        }
    }
    
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {


        if(k==n)
            return 0; 
        vector<pair<int,pair<int,int>>>v;
        vector<vector<pair<int,int>>>graph(n);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0]; int to = edges[i][1]; 
            int w = edges[i][2];
            graph[from].push_back({to,w});
            graph[to].push_back({from,w});
            v.push_back({w,{from,to}});

        }
        sort(v.rbegin(), v.rend());

        int start = 0;
        int end = v.size()-1;
        int pos = -1; int mid = -1; 
        while(start<=end)
        {
            mid = start + (end-start)/2;
            vector<bool>vis(n,false);
            int comp = 0; 
            bool z = true;
            for(int i = 0; i< n; i++)
            {   
                if(!vis[i])
                {
                    comp++;
                    dfs(i, graph,vis, v[mid].first);
                }
                if(comp>k)
                {
                    z = false;
                    break;
                }
            }
            if(z)
            {
                pos = mid; 
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return v[pos].first;

        
    }
};