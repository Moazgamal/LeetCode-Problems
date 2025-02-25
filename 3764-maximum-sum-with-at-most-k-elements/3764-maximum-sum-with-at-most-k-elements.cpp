class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0; 
        if(k==0)
            return 0; 
        priority_queue<pair<int,int>>pq;
        for(int r = 0; r< grid.size(); r++)
            {
                for(int c = 0; c< grid[0].size(); c++)
                    {
                        pq.push({grid[r][c], r});
                    }
            }
        while(!pq.empty())
            {
                auto p = pq.top();
                pq.pop();
                if(limits[p.second] > 0)
                {
                    ans += p.first;
                    limits[p.second]--;
                    k--;
                }
                if(k == 0)
                    return ans;
                
            }
        return ans;
        
    }
};