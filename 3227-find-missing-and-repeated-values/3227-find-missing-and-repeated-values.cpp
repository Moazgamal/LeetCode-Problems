class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        vector<int> res(2,0);
        for(int i= 0; i< grid.size(); i++)
        {
            for(int j = 0; j< grid[0].size(); j++)
            {
                if(++mp[grid[i][j]]==2)
                {
                    res[0] = grid[i][j];
                }
            }
        }
        for(int i = 1; i<= grid.size()*grid.size(); i++)
        {
            if(mp.count(i) ==0)
            {
                res[1] = i;
                break;
            }
        }return res;
        
    }
};