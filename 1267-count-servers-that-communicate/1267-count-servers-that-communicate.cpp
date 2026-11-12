class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c =0; c< grid[0].size(); c++)
            {
                if(grid[r][c] ==1)
                {
                    rows[r]++; cols[c]++;
                }
            }
        }int ans = 0; 
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c =0; c< grid[0].size(); c++)
            {
                if(grid[r][c] ==1)
                {
                    if(rows[r] >1 || cols[c] > 1)
                        ans++;
                }
            }
        }return ans;
        
        
    }
};