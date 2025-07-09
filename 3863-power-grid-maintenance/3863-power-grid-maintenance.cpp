class Solution {
    void dfs(int node, vector<vector<int>>&g, vector<int>&group,
    int &cnt, unordered_map<int, vector<int>>&mp)
    {
        group[node] = cnt;
        mp[cnt].push_back(node);
        for(int i = 0; i< g[node].size(); i++)
        {
            if(group[g[node][i]] == 0)
            {
                dfs(g[node][i], g, group, cnt, mp );
            }
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        unordered_map<int, vector<int>>mp;
        vector<vector<int>>graph(c+1);
        vector<int> ans;
        for(int i = 0; i< connections.size(); i++)
        {
            int from = connections[i][0];
            int to = connections[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vector<int>group(c+1, 0);
        
        int cnt = 1; 
        for(int i = 1; i<=c; i++)
        {
            if(group[i] == 0)
            {
                dfs(i,graph, group, cnt,mp);
                sort(mp[cnt].rbegin(), mp[cnt].rend());
                cnt++;
            }
        }
        vector<int> group2 = group;
        
        for(int i = 0; i< queries.size(); i++)
        {
            int first = queries[i][0]; 
            int second = queries[i][1];
            if(first == 2)
            {
                group[second] = -1;
            }
            else
            {
                if(group[second] !=-1)
                {
                    ans.push_back(second);
                }
                else
                {
                    int g = group2[second];
                    
                    if(mp[g].size() ==0)
                    {
                        ans.push_back(-1);
                    }
                    else
                    {
                        while(mp[g].size()>0 && group[mp[g][mp[g].size()-1]] == -1)
                        {
                            mp[g].pop_back();
                        }
                        if(mp[g].size()==0)
                        {
                            ans.push_back(-1);
                        }
                        else
                        {
                            ans.push_back(mp[g][mp[g].size()-1]);
                        }
                    }
                }
            }

        }
        return ans;
        
    }
};