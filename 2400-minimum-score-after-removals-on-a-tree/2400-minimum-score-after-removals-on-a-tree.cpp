class Solution {
    int dfs(int node, vector<int>&xors, vector<bool> &vis, vector<vector<int>>&g,
    vector<int>&nums,  vector<pair<pair<int,int>,string>> &newEdges, string &str)
    {
        vis[node] = true;
        xors[node] = nums[node];
        int cnt = 1; 
        for(int i= 0; i< g[node].size(); i++)
        {
            if(!vis[g[node][i]])
            {
                str.push_back(cnt+'0');
                newEdges.push_back({{node, g[node][i]}, str});
                xors[node] ^= dfs(g[node][i], xors, vis, g, nums,newEdges,str);
                str.pop_back();
                cnt++;
            }
        }
        return xors[node];
    }
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int ans = INT_MAX;
        vector<vector<int>> graph(nums.size());
        for(int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0]; int to = edges[i][1];
            graph[from].push_back(to); graph[to].push_back(from);
        }

        vector<int> xors(nums.size(), 0);
        vector<bool>vis(nums.size(), false);
        vector<pair<pair<int,int>,string>> newEdges;
        string str = "1";
        int totalXor = dfs(0, xors, vis, graph, nums, newEdges, str);
        for(int i = 0; i< newEdges.size(); i++)
        {
            int from = newEdges[i].first.first;
            int to = newEdges[i].first.second;
            int firstXor = xors[to];
            int secondXor = totalXor ^ firstXor;
            string ss = newEdges[i].second;
            
            for(int j = i+1; j< newEdges.size(); j++)
            {
                int from2 = newEdges[j].first.first;
                int to2 = newEdges[j].first.second;
                int thirdXor = xors[to2];
                string ss2 = newEdges[j].second;
                
                if (ss2.size() <= ss.size() && ss.substr(0, ss2.size()) == ss2) {
                    // Edge2 is ancestor of Edge1
                    int part1 = thirdXor;
                    int part2 = firstXor ^ thirdXor;
                    int part3 = totalXor ^ firstXor;
                    int maxi = max({part1, part2, part3});
                    int mini = min({part1, part2, part3});
                    ans = min(ans, maxi - mini);
                }
                else if (ss.size() <= ss2.size() && ss2.substr(0, ss.size()) == ss) {
                    // Edge1 is ancestor of Edge2
                    int part1 = firstXor ^ thirdXor;
                    int part2 = thirdXor;
                    int part3 = totalXor ^ firstXor;
                    int maxi = max({part1, part2, part3});
                    int mini = min({part1, part2, part3});
                    ans = min(ans, maxi - mini);
                } else {
                    // Completely separate subtrees
                    int part1 = firstXor;
                    int part2 = thirdXor;
                    int part3 = totalXor ^ firstXor ^ thirdXor;
                    int maxi = max({part1, part2, part3});
                    int mini = min({part1, part2, part3});
                    ans = min(ans, maxi - mini);
                }
                
            }
        }
        return ans; 
        
    }
};