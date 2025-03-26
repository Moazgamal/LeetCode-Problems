class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if(grid.size()==1 && grid[0].size()==1)
            return 0; 
        vector<int> v;
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                v.push_back(grid[r][c]);
            }
        }
        sort(v.begin(), v.end());
        int sz= v.size()/2 ;
        int ans = 0; 
        int num = v[sz];
        for(int i =0; i<v.size(); i++)
        {
            if(abs(num-v[i])%x !=0)
                return -1;
            ans+= abs(num-v[i])/x; 
        }
        return ans;

        
    }
};