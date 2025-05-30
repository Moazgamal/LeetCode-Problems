class Solution {
    void BFS(int node, vector<vector<int>> &graph,int &evens, int &odds,unordered_set<int> &s1)
    {
        queue<int>q;
        bool e = true;
        q.push(node);
        vector<bool> vis(graph.size(), false);
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                vis[cur] = true;
                if(e)
                {
                    evens++;
                    s1.insert(cur);
                }
                else
                    odds++;
                for(int i = 0; i< graph[cur].size(); i++)
                {
                    if(!vis[graph[cur][i]])
                    {
                        
                        q.push(graph[cur][i]);
                    }
                }

            }
            e = !e;
        }

    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

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
        int evens1 = 0;
         int odds1 = 0; 
         int evens2 = 0; 
         int odds2 = 0; 
        unordered_set<int> s1;
        unordered_set<int> s2;
         BFS(0,graph1, evens1, odds1, s1);
         BFS(0,graph2, evens2, odds2, s2);
         int maxi = max(evens2, odds2);
         for(int i = 0; i< edges1.size()+1; i++)
         {
            if(s1.find(i) != s1.end())
            {
                ans[i] = maxi+evens1;
            }
            else
                ans[i] = maxi+odds1;
         }return ans; 
         


        
        
    }
};