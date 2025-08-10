class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rlimit = x+k;
        int climit = y+k;
        for(int c = y; c< climit; c++)
        {
            int i = x; int j = x+k-1;
            while(i<j)
            {
                swap(grid[i][c], grid[j][c]);
                i++; j--;
            }
        }
        return grid;
        
    }
};