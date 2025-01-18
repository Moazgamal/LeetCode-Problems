class Solution {
    void fn(int node,int maxi, vector<vector<pair<int,int>>>&graph, int &cnt,vector<bool>&vis,
    vector<int>&outdegree)
    {
        vis[node]= true;
        for(int i = graph[node].size()-1; i>=0 ; i--)
        {
            int newNode = graph[node][i].first;
            int w = graph[node][i].second;
            if(vis[newNode] == false )
            {
                if(w <= maxi)
                {
                    cnt++;
                    fn(newNode, maxi,graph,cnt,vis,outdegree);
                }
                else
                    outdegree[newNode]--;
            }
            else
                outdegree[newNode]--;
        }
    }
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<pair<int,int>>>graph(n);
        unordered_map<int,int>mp;
        vector<int>v;
        vector<int> outdegree(n,0);
        for(int i = 0; i< edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int w = edges[i][2];
            graph[to].push_back({from,w});
            if(mp.count(w) ==0)
                v.push_back(w);
            outdegree[from]++;
        }
        sort(v.begin(), v.end());
        int ans = -1;
        for(int i = v.size()-1; i>=0; i--)
        {
            int maxi = v[i];
            int cnt = 0; 
            vector<bool>vis(n,false);
            fn(0,maxi,graph,cnt,vis,outdegree);
            bool m = true;
            for(int i = 0; i<outdegree.size(); i++)
            {
                if(outdegree[i] > threshold)
                {
                    m = false; break;
                }
            }
            if(cnt == n-1)
                {
                    if(m == true)
                        ans = v[i];
                }
            else
                return ans;
        }
        return ans;
        
    }
};