class Solution {
    void dfs(int node, vector<vector<int>>&graph, vector<int> &parent)
    {
        for(int i = 0; i< graph[node].size(); i++)
        {
            if(parent[node] == graph[node][i])
                continue;
            parent[graph[node][i]]= node;
            dfs(graph[node][i], graph, parent);
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>>graph(amount.size());
        vector<int> parent(amount.size());
        parent[0] = -1;
        int ans = INT_MIN; 

        for(int i = 0; i< edges.size();i++)
        {
            int from = edges[i][0]; int to =  edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        dfs(0, graph, parent);
        queue<pair<char,pair<int,int>>>q;
        q.push({'b',{bob,amount[bob]}});
        q.push({'a',{0,amount[0]}});
        amount[0]=0;
        amount[bob]=0;
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            unordered_set<int>st;
            int am = 0;
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                int curamount = cur.second.second;
                if(cur.first == 'b')
                {
                    int p = parent[cur.second.first];
                    if(p!=-1)
                    {
                        st.insert(p);
                        q.push({'b',{p,0}});
                        am= amount[p];
                        amount[p]=0;
                    }
                }
                else
                {
                    if(graph[cur.second.first].size()==1)
                    {
                        if(parent[cur.second.first]==graph[cur.second.first][0])
                        {
                            ans=max(ans,curamount);
                            continue;
                        }
                    }
                    for(int i =0; i< graph[cur.second.first].size(); i++)
                    {
                        if(parent[cur.second.first] == graph[cur.second.first][i])
                            continue;
                        int node = graph[cur.second.first][i];
                        if(st.find(graph[cur.second.first][i]) != st.end())
                        {
                            q.push({'a',{node,curamount+am/2}});
                            amount[node]=0;
                        }
                        else
                        {
                            q.push({'a',{node,curamount+amount[node]}});
                            amount[node]=0;
                        }
                    }

                }

            }
        }
        return ans;
    }
};