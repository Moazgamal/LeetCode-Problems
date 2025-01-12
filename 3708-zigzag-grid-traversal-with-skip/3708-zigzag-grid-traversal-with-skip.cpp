class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool s = true;
        bool take = true;
        vector<int> ans;
        for(int r = 0; r< grid.size(); r++)
            {
                if(s==true)
                {
                    for(int c  =0; c<grid[0].size(); c++)
                    {
                        if(take)
                        {
                            ans.push_back(grid[r][c]);
                            take = !take;
                        }
                        else
                        {
                            take=!take; continue;
                        }
                    }
                    s=!s;
                }
                else
                {
                    for(int c  =grid[0].size()-1; c>=0; c--)
                    {
                        if(take)
                        {
                            ans.push_back(grid[r][c]);
                            take = !take;
                        }
                        else
                        {
                            take=!take; continue;
                        }
                    }
                    s=!s;
                }
            }return ans;
        
    }
};