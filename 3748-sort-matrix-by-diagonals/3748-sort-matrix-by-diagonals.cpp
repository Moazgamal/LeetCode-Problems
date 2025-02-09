class Solution {
bool isvalid(int r, int c, vector<vector<int>>&grid)
{
    if(r<0 || r>=grid.size()|| c<0 || c>= grid[0].size())
        return false;
    return true;
}
void fn1(int r, int c, vector<vector<int>>&grid)
{
    vector<int> v;
    int oldr = r; 
    int oldc = c;
    while(isvalid(r,c, grid))
        {
            v.push_back(grid[r][c]);
            r++; c++;
        }
    sort(v.begin(), v.end());
    int i = v.size()-1; 
    while(isvalid(oldr, oldc, grid))
        {
            grid[oldr][oldc] = v[i];
            oldr++; oldc++;
            i--;
        }
}
void fn2(int r, int c, vector<vector<int>>&grid)
{
    vector<int> v;
    int oldr = r; 
    int oldc = c;
    while(isvalid(r,c, grid))
        {
            v.push_back(grid[r][c]);
            r++; c++;
        }
    sort(v.begin(), v.end());
    int i = 0; 
    while(isvalid(oldr, oldc, grid))
        {
            grid[oldr][oldc] = v[i];
            oldr++; oldc++;
            i++;
        }
}
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int c = 0; 
        for(int r = 0; r< grid.size(); r++)
            {
                fn1(r,c, grid);
            }
        int r=0; 
        for(int c =1; c<grid[0].size(); c++)
            {
                fn2(r, c, grid);
            }
        return grid;
        
    }
};