class Solution {
    void dfs(int node, int t, unordered_map<int,map<int,vector<int>>>&mp, unordered_map<int,int>&mp2, 
    vector<bool>&vis)
    {
        vis[node] = true;
        mp2[node]=t;
        for(auto i: mp[node])
        {
            int time = i.first;
            if(time < t)
                continue;
            for(auto j: i.second)
            {
                int newNode = j; 
                if(!vis[newNode] && mp2.count(newNode)==0
                ||!vis[newNode] && mp2[newNode]>=time
                 || vis[newNode] && mp2[newNode] > time)
                {
                    dfs(newNode, time, mp, mp2, vis);
                }
            }
        }
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>ans;
        unordered_map<int,map<int,vector<int>>>mp;
        for(int i = 0; i< meetings.size(); i++)
        {
            int f = meetings[i][0];
            int to = meetings[i][1];
            int t = meetings[i][2];
            mp[f][t].push_back(to);
            mp[to][t].push_back(f);
        }
        unordered_map<int,int>mp2;
        mp2[0]=0;
        mp2[firstPerson]=0;
        mp[0][0].push_back(firstPerson);
        mp[firstPerson][0].push_back(0);
        vector<bool>vis(n+1,false);
        dfs(0, 0, mp, mp2, vis);
        for(int i = 0; i< vis.size(); i++)
        {
            if(vis[i] == true)
            {
                ans.push_back(i);
            }
        }
        return ans; 

        
    }
};