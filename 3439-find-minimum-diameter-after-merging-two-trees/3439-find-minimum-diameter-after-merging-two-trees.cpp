class Solution {
    int Diameter(vector<vector<int>> &graph)
    {
        queue<int> q;
         vector<int> degrees(graph.size());
        for(int i = 0; i< graph.size(); i++)
        {
            degrees[i] = graph[i].size();
            if(degrees[i] == 1)
            {
                q.push(i);
            }
        }
       int noofnodes = graph.size(); 
        int level=0;
        for( int sz= q.size();  noofnodes >2 && !q.empty(); sz = q.size())
        {
            while(sz--)
            {
                auto cur = q.front(); 
                q.pop();
                noofnodes--;
                for(int i = 0; i< graph[cur].size(); i++)
                {
                    int node = graph[cur][i];
                    if( --degrees[node]== 1 )
                    {
                        q.push(node);
                    }
                }
            }
            level++;
        }
        if(noofnodes == 2)
            return 2*level +1;
        return 2*level;

    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {


        vector<vector<int>> graph1(edges1.size()+1);
        vector<vector<int>> graph2(edges2.size()+1);
        for(int i = 0; i< edges1.size(); i++)
        {
            int from = edges1[i][0];
            int to = edges1[i][1];
            graph1[from].push_back(to);
            graph1[to].push_back(from);
           
        }
        for(int i = 0; i< edges2.size(); i++)
        {
            int from = edges2[i][0];
            int to = edges2[i][1];
            graph2[from].push_back(to);
            graph2[to].push_back(from);
            
        }
        int Min1 = Diameter(graph1  );
        int Min2 = Diameter(graph2  );
        int maxi = max(Min1, Min2);
        
       int comb = ceil(Min1 / 2.0) + ceil(Min2 / 2.0) + 1;
        return max(maxi, comb);
        
    }
};