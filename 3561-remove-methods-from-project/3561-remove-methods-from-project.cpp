class Solution {
    void dfs(int node, vector<vector<int>>&graph, unordered_map<int,int>&mp)
    {
        mp[node]++;
        for(int i = 0; i< graph[node].size(); i++)
        {
            if(mp.count(graph[node][i])==0)
            {
                dfs(graph[node][i], graph, mp);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph1(n);        
        vector<vector<int>> graph2(n);

        for(int i = 0; i< invocations.size(); i++)
        {
            int from = invocations[i][0];
            int to = invocations[i][1];
            graph1[from].push_back(to);

            graph2[to].push_back(from);            

        }
        unordered_map<int,int>mp;
        dfs(k,graph1,mp);
        vector<int>result;
        bool c = false;
        for(int i = 0; i< n; i++)
        {
            bool tmp=false;
            if(mp.count(i)==0)
            {
                for(int j=0; j<graph1[i].size(); j++)
                {
                    if(mp.count(graph1[i][j])>0)
                        tmp=true;
                }
            }
            if(tmp)
            {
                c=true; break;
            }
            
           
        }
        for(int i = 0; i< n; i++)
        {
            if(mp.count(i)==0)
                result.push_back(i);
            else if(c)
                result.push_back(i);
        }
        return result;
        
    }
};