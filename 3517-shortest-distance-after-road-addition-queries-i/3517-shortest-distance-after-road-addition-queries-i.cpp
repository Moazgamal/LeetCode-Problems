class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {


        vector<vector<int>> graph(n, vector<int>(n,INT_MAX/2));
        for(int i = 0; i< n; i++)
        {
            graph[i][i]=0;
            int k = 0;
            for(int j = i ; j< n; j++)
            {
                graph[i][j] = k++;
            }
        }
        int mini = graph[0][n-1];
        vector<int>result(queries.size());
        for(int i = 0; i< queries.size(); i++)
        {
            int from = queries[i][0];
            int to = queries[i][1];
            graph[from][to] = 1;
            for(int i = from; i>=0 ; i--)
            {
                for(int j = to; j< n; j++)
                {
                    graph[i][j]= min(graph[i][j], graph[i][from]+1+graph[to][j]);
                }
            }
            result[i] = graph[0][n-1];
        }return result;
        
    }
};