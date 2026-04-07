class Solution {
    int dfs(int node, vector<vector<int>>&g, vector<int>&good, vector<int>&ans, int parent)
    {
        int acc = 0;    
        if(good[node] == 0)
            acc = -1;
        else
            acc = 1; 
        ans[node]= acc;
        int pos = 0; 
        for(int i = 0; i< g[node].size(); i++)
        {
            if(g[node][i] == parent)
                continue;
            int m = dfs(g[node][i], g, good, ans, node);
            if(m>0)
                pos+=m;
            if(m > 0)
                ans[node] = max(ans[node], pos+acc);
        }
        return ans[node];
    }
    void dfs2(int node, vector<vector<int>>&g, vector<int>&good, vector<int>&ans, int p)
    {
        if(ans[node]<0)
        {
            if(ans[p]<0)
            {
                for(int i = 0; i< g[node].size(); i++)
                {
                    if(g[node][i] == p)
                        continue;
                    dfs2(g[node][i], g, good, ans, node);
                }
            }
            else
            {
                int acc = 0; 
                if(good[node] == 0)
                    acc =-1;
                else
                    acc = 1; 
                ans[node] = max(ans[node], acc+ans[p]);
                for(int i = 0; i< g[node].size(); i++)
                {
                    if(g[node][i] == p)
                        continue;
                    dfs2(g[node][i], g, good, ans, node);
                }
            }
        }
        else 
        {
            if(ans[p] <0)
            {
                for(int i = 0; i< g[node].size(); i++)
                {
                    if(g[node][i] == p)
                        continue;
                    dfs2(g[node][i], g, good, ans, node);
                }
                cout<<"fff\n";;
            }
            else
            {
                if(ans[node]< ans[p])
                    ans[node] += (abs(ans[p]-ans[node]));
                for(int i = 0; i< g[node].size(); i++)
                {
                    if(g[node][i] == p)
                        continue;
                    dfs2(g[node][i], g, good, ans, node);
                }
            }
        }
    }
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {

        vector<int>ans(n,-1);
        vector<vector<int>>g(n);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            g[from].push_back(to);
            g[to].push_back(from);
        }
        dfs(0, g, good, ans, -1);
        for(int i = 0; i< g[0].size(); i++)
        {
            dfs2(g[0][i], g, good, ans, 0);
        }
        return ans; 
    }
};