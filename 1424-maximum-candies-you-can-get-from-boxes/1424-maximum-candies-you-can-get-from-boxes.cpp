class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int ans = 0; 
        queue<int>q;
        vector<bool>reachable(status.size(), false);
        vector<bool>vis(status.size(), false);
        for(int i = 0; i< initialBoxes.size(); i++)
        {
            if(status[initialBoxes[i]] == 1)
            {
                q.push(initialBoxes[i]);
                vis[initialBoxes[i]]= true;
            }
            else
                reachable[initialBoxes[i]]= true;
        }
        for(int sz = q.size(); !q.empty(); sz= q.size())
        {
            auto cur = q.front(); q.pop();
            ans+= candies[cur];
            for(int j = 0; j< keys[cur].size(); j++)
            {
                int box = keys[cur][j];
                if(!vis[box])
                {
                    if(reachable[box])
                    {
                        q.push(box); vis[box]= true;
                    }
                    else
                        status[box]=1;
                }
            }
            for(int i = 0; i< containedBoxes[cur].size(); i++)
            {
                int box = containedBoxes[cur][i];
                
                if(!vis[box])
                {
                    if(status[box] == 1)
                    {
                        q.push(box);
                        vis[box] = true;
                    }
                    else
                        reachable[box] = true;
                }
            }
        }
        return ans; 
        
    }
};