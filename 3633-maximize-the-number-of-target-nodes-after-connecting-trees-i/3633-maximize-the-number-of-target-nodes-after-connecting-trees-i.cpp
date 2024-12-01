class Solution {
    int BFS(int node, vector<vector<int>> &graph, int k)
    {
        queue<pair<int,int>> q; q.push({node,-1});
        int ans = 0; 
        for(int level = k, sz = q.size(); level>0 && !q.empty() ; level--,sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                for(int i = 0; i< graph[cur.first].size(); i++)
                {
                    if(graph[cur.first][i] != cur.second)
                        {
                            ans++; q.push({graph[cur.first][i],cur.first});
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
            ans[i] += BFS(i, graph1, k);
        }
        int maxi = 1;
        
        if(k>1)
        { 
            for(int i = 0; i< graph2.size(); i++)
            {
                maxi = max(maxi, 1+BFS(i, graph2, k-1));
            }
        }
        for(int i = 0; i< ans.size(); i++)
        {
            ans[i] += maxi;
        }
        return ans;

        
    }
};