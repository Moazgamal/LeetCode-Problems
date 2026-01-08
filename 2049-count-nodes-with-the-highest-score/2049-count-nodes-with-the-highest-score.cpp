class Solution {
    int dfs(int node, vector<vector<int>>&g, vector<long long>&v)
    {
        if(g[node].size()==0)
            return v[node]=1; 
        int acc = 1; 
        int i = 0; int sz = g[node].size();
        while(i< sz)
        {
            acc += dfs(g[node][i], g, v); i++;
        }
         v[node] = acc;
        return v[node];
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int sz = (int)parents.size();
        vector<vector<int>>g(sz);
        int i = 1;
        while(i< sz)
        {
            int p = parents[i];
            g[p].push_back(i);
            i++;
        }

        vector<long long>v(sz);

        int totalNodes = dfs(0, g, v);

        vector<long long>scores(sz);

         if(g[0].size() == 0)
            scores[0] = 0;
        else if(g[0].size() == 1)
            scores[0] = v[g[0][0]];
        else
            scores[0] = v[g[0][0]]*v[g[0][1]];

        long long maxi = scores[0];
        int node = 1;
        while(node< sz)
        {
            if(g[node].size() == 0)
                scores[node] = totalNodes-1;
            else if(g[node].size() == 1)
                scores[node] = v[g[node][0]]*(totalNodes-1-v[g[node][0]]);
            else
                scores[node] = v[g[node][0]]*v[g[node][1]]*(totalNodes-1-v[g[node][0]]-v[g[node][1]]);
            
            maxi = max(maxi, scores[node]);
            node++;
        }
        int ans = 0; 
        i = 0; 
        while(i< sz)
        {
            if(scores[i] == maxi)
                ans++;
            i++;
        }
        return ans; 
        
    }
};