class Solution {
    
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
if(edges.size()==0)
    return 1; 
        int ans = 1;
        vector<vector<int>>graph(colors.size());
        vector<int> indegree(colors.size(),0);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            if(from == to)
                return -1;
            graph[from].push_back(to);
            indegree[to]++;
        }
        bool f = true;
        
        for(int i = 0; i< indegree.size(); i++)
        {
            if(indegree[i] == 0 && graph[i].size() != 0)
            {
                f = false;
                break;
            }
        }
        if(f)
            return - 1; 
        vector<vector<int>> y(colors.size(), vector<int>(26,0));
        queue<int>q;
        vector<int> v(26,0);
        for(int i = 0; i< indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        for(int sz = q.size(); !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                y[cur][colors[cur]-'a']++;
                ans = max(ans, y[cur][colors[cur]-'a']);
                for(int i = 0; i< graph[cur].size(); i++)
                {
                    --indegree[graph[cur][i]];
                    for(int j = 0; j< 26; j++)
                    {
                        y[graph[cur][i]][j] = max(y[graph[cur][i]][j],
                        y[cur][j]);
                        ans = max(ans,y[graph[cur][i]][j] );
                    }
                    if(indegree[graph[cur][i]] == 0)
                    {
                        q.push(graph[cur][i]);
                    }
                }
                
               
            }
        }
        for(int i = 0; i< indegree.size(); i++)
        {
            if(indegree[i] != 0)
                return -1;;; 
        }
        
        return ans; 

        
        
    }
};