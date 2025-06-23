class Solution {
    void dfs1(int node, int p,long long acc,vector<vector<int>>&g, vector<int>&cost,
                  vector<long long>&path,
                  vector<int>&parent,
                  vector<int>&leafs)
    {
        parent[node] = p;
        path[node] = acc+cost[node];
        bool s = true;
        for(int i = 0; i< g[node].size(); i++)
        {
            if(g[node][i] == p)
                continue;
            s= false;
            dfs1(g[node][i], node, path[node],g,cost,path,parent,leafs);
        }
        if(s)
            leafs.push_back(node);
    }
    long long dfs2(int node, int parent, vector<vector<int>>&g, vector<long long>&changes)
    {
        if(changes[node] != LLONG_MAX)
            return changes[node];
        long long mini = LLONG_MAX;
        for(int i = 0; i< g[node].size(); i++)
        {
            if(g[node][i] == parent)
                continue;
            mini = min(mini, dfs2(g[node][i], node, g, changes));
        }
        return changes[node] = mini;
    }
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {

        vector<vector<int>>graph(n);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vector<long long> path(n,0);
        vector<int>parent(n,-1);
        vector<int> leafs;
        dfs1(0,-1,0,graph,cost,path,parent,leafs);
        
        long long MaxSum= 0;
        for(int i =0; i< leafs.size(); i++)
        {
            MaxSum = max(MaxSum,path[leafs[i]]);
        }
        vector<long long> changes(n, LLONG_MAX);
        for(int i = 0; i< leafs.size(); i++)
        {
            changes[leafs[i]]=MaxSum-path[leafs[i]];
        }
        int ans = 0; 
        dfs2(0,-1,graph,changes);
        for(int i = 1; i< n; i++)
        {
            if(changes[i] > changes[parent[i]])
                ans++;
        }
       
        return ans;
    }
};