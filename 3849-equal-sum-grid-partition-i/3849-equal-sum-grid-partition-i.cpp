class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(),0);
        long long tot = 0; 
        for(int r = 0; r< grid.size(); r++)
            {
                long long sum = 0; 
                for(int c = 0; c< grid[0].size(); c++)
                    {
                        sum += grid[r][c];
                    }
                rows[r] = sum;
                tot += sum;
            }
        for(int c = 0; c< grid[0].size(); c++)
            {
                long long sum = 0; 
                for(int r = 0; r< grid.size(); r++)
                    {
                        sum += grid[r][c];
                    }
                cols[c] = sum;
            }
       
        long long sum1 = 0; 
        for(int i = 0; i< rows.size()-1; i++)
            {
                sum1 += rows[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        sum1 = 0; 
        for(int i = 0; i< cols.size()-1; i++)
            {
                sum1 += cols[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        return false;
        
        
    }
};