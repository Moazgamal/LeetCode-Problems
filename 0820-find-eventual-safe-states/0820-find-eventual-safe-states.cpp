class Solution {
    bool dfs(int node, vector<vector<int>>&v, vector<bool>&vis, vector<int> &dp)
    {
        vis[node] = true;
        if(v[node].size() ==0)
            return dp[node]=true;
        auto ret = dp[node];
        if(ret == true)
            return true;
        for(int i = 0; i< v[node].size(); i++)
        {
            if(!vis[v[node][i]])
            {
                if(dfs(v[node][i], v, vis, dp) == false)
                    return dp[node] = false;
            }
            else
            {
                if(dp[v[node][i]] == true)
                    continue;
                return dp[node] = false;
            }
        }
        return dp[node] = true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> v(graph.size());
        for(int i = 0 ;i< graph.size(); i++)
        {
            int from = i;
            for(int j= 0; j< graph[i].size(); j++)
            {
                v[from].push_back(graph[i][j]);
            }
        }
        vector<bool> vis(graph.size(), false);
        vector<int> result;
        vector<int> dp(v.size()+1, 0);
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i].size() ==0)
            {
                result.push_back(i); continue;
            }
            if(!vis[i])
            {
                dfs(i, v,vis, dp);
                if(dp[i] == true)
                    result.push_back(i);
            }
            else
            {
                if(dp[i] == true)
                    result.push_back(i);
            }
        }
        return result;
        
    }
};