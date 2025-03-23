class Solution {
void dfs(int node, vector<unordered_set<int>>&graph, vector<bool> &vis, int parent)
{
    vis[node] = true;
    for(auto x: graph[node])
        {
            if(!vis[x] && x != parent)
            {
                dfs(x, graph, vis, node);
            }
        }
}
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<unordered_set<int>>graph(properties.size());
        vector<unordered_set<int>>graph2(properties.size());
        for(int i = 0; i< properties.size(); i++)
            {
                for(int j = 0; j< properties[i].size(); j++)
                    {
                        graph2[i].insert(properties[i][j]);
                    }
            }
        for(int i = 0; i< properties.size(); i++)
            {
                int node = i ; 
                if(graph2[i].size()<k)
                    continue;
                for(int j = i+1; j< properties.size(); j++)
                    {
                        if(graph2[j].size()< k)
                            continue;
                        if(graph[j].find(i) != graph[j].end())
                            continue;
                        int cnt = 0; 
                        for(auto u: graph2[j])
                            {
                                if(graph2[i].find(u) != graph2[i].end())
                                {
                                    cnt++;
                                }
                            }
                        if(cnt >=k)
                        {
                            graph[i].insert(j);
                            graph[j].insert(i);
                        }
                    }
            }
        int ans = 0; 
        vector<bool>vis(properties.size(), false);
        for(int i = 0; i< graph.size(); i++)
            {
                if(!vis[i])
                {
                    ans++;
                    dfs(i, graph, vis, -1);
                }
            }
        return ans;
    }
};