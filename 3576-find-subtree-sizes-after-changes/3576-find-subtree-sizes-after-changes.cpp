class Solution {
    void dfs(int node, vector<vector<int>> &graph, string &s , vector<int>&parent, unordered_map<char,int>&mp)
{
    
    if(mp.count(s[node]) ==0)
    {
        mp[s[node]]= node;
        for(int i = 0; i< graph[node].size(); i++)
        {
            dfs(graph[node][i], graph, s, parent, mp);
        }
        mp.erase(s[node]);
    }
    else
    {
        int oldnode =mp[s[node]];
        parent[node] = mp[s[node]];
        
        mp[s[node]]= node;
        for(int i = 0; i< graph[node].size(); i++)
        {
            dfs(graph[node][i], graph, s, parent, mp);
        }
        mp[s[node]] = oldnode;
    }
    
    
    
}
int fn(int node, vector<int>&ans, vector<vector<int>>&graph)
{
    int cnt = 1;
    for(int i = 0; i< graph[node].size(); i++)
        {
            cnt += fn(graph[node][i], ans, graph);
        }
    ans[node] = cnt;
    return cnt;
}
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        vector<int> ans(parent.size(),0);
        vector<vector<int>>graph(parent.size());
        for(int i = 1; i< parent.size(); i++)
            {
                int child = i;
                int parentt = parent[i];
                graph[parentt].push_back(child);
            }
        unordered_map<char,int>mp;
        dfs(0, graph, s, parent, mp);
        vector<vector<int>>graph2(parent.size());
        for(int i = 1; i< parent.size(); i++)
            {
                int child = i;
                int parentt = parent[i];
                graph2[parentt].push_back(child);
            }
        fn(0, ans, graph2);
        return ans;

        
    }
};