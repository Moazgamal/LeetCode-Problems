class Solution {
    int dfs(int node, vector<vector<int>>&g, vector<int>&v)
    {
        if(g[node].size()==0)
            return v[node]=1; 
        int acc = 1; 
        for(int i =0; i< g[node].size(); i++)
        {
            acc += dfs(g[node][i], g, v);
        }
         v[node] = acc;
        return v[node];
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {

        vector<vector<int>>g(parents.size());
        for(int i = 1; i< parents.size(); i++)
        {
            int p = parents[i];
            g[p].push_back(i);
        }
        vector<int>v(parents.size());
        int totalNodes = dfs(0, g, v);
        vector<long long>scores(parents.size());
        for(int i = 0; i< g.size(); i++)
        {
            int node = i; 
            scores[i] = 0;
            if(i == 0)
            {
                if(g[node].size() == 0)
                    scores[i] = 0;
                else if(g[node].size() == 1)
                    scores[i] = v[g[node][0]];
                else
                    scores[i] = (long long)v[g[node][0]]*v[g[node][1]];
            }
            else
            {
                
                if(g[node].size() == 0)
                    scores[i] = totalNodes-1;
                else if(g[node].size() == 1)
                    scores[i] = (long long)v[g[node][0]]*(totalNodes-1-v[g[node][0]]);
                else
                    scores[i] = (long long)v[g[node][0]]*v[g[node][1]]*(totalNodes-1-v[g[node][0]]-v[g[node][1]]);
            }
        }
        sort(scores.rbegin(), scores.rend());
        int ans = 1; 
        int i = 1; 
        while(i< scores.size() && scores[i] == scores[0])
        {
            ans++;
            i++;
        }
        return ans; 
        
    }
};