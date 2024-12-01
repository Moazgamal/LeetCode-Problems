class Solution {
    int BFS(int node, vector<vector<int>> &graph, vector<bool> &vis, int k)
    {
        queue<int> q; q.push(node);
        int ans = 0; 
        for(int level = k, sz = q.size(); level>0 && !q.empty() ; level--,sz = q.size())
        {
            while(sz--)
            {
                int cur = q.front(); q.pop();
                vis[cur] = true;
                for(int i = 0; i< graph[cur].size(); i++)
                {
                    if(vis[graph[cur][i]] == false)
                    {
                        ans++; q.push(graph[cur][i]);
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        vector<vector<int>> graph1(edges1.size()+1);
        vector<vector<int>> graph2(edges2.size()+1);
        for(int i = 0; i< edges1.size(); i++)
        {
            int from  = edges1[i][0];
            int to = edges1[i][1];
            graph1[from].push_back(to);
            graph1[to].push_back(from);
        }
        for(int i = 0; i< edges2.size(); i++)
        {
            int from  = edges2[i][0];
            int to = edges2[i][1];
            graph2[from].push_back(to);
            graph2[to].push_back(from);
        }
        vector<int> ans(edges1.size()+1, 1);
        if(k == 0)
            return ans;
        for(int i = 0; i< graph1.size(); i++)
        {
            vector<bool>vis(graph1.size(),false);
            ans[i] += BFS(i, graph1, vis, k);
        }
        int maxi = 1;
        if(k>1)
        { 
            for(int i = 0; i< graph2.size(); i++)
            {
                vector<bool>vis2(graph2.size(),false);
                maxi = max(maxi, 1+BFS(i, graph2, vis2, k-1));
            }
        }
        cout<<maxi<<"\n";
        for(int i = 0; i< ans.size(); i++)
        {
            cout<<ans[i]<<"\n";
            ans[i] += maxi;
        }
        return ans;

        
    }
};