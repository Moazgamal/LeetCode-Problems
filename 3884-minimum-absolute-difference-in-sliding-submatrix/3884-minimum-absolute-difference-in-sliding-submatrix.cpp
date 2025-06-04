class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows-k+1, vector<int>(cols-k+1)); 

        for(int r= 0; r< rows; r++)
        {
            if(r+k-1 == rows)
                break;
            
            vector<int> v; 
            vector<int> y;
            for(int c = 0; c< cols; c++)
            {
                int ans1 = INT_MAX;
                if(c+k-1 == cols)
                    break;
                if(v.size()==0)
                {
                    for(int col = c; col< c+k; col++)
                    {
                        for(int row = r ; row< r+k; row++)
                        {
                            v.push_back(grid[row][col]);
                        }
                    }
                     y = v;
                    sort(v.begin(), v.end());
                    for(int i = 0; i< v.size()-1; i++)
                    {
                        if(v[i] == v[i+1])
                        {
                            int j = i+1;
                            while(j< v.size() && v[i] == v[j])
                            {
                                j++;
                            }
                            if(j== v.size())
                            {
                                break;
                            }
                            ans1 = min(ans1, abs(v[i]-v[j]));
                            i=j-1;
                        }
                        else
                        {
                            ans1 = min(ans1, abs(v[i]-v[i+1]));
                        }
                    }
                    if(ans1==INT_MAX)
                    {
                        ans[r][c] = 0;
                    }
                    else
                        ans[r][c] = ans1;
                }
                else
                {
                    reverse(y.begin(), y.end());
                    int _k= k;
                    while(_k--)
                        y.pop_back();
                    reverse(y.begin(), y.end());
                    v=y;
                    for(int row= r; row< r+k; row++)
                    {
                        v.push_back(grid[row][c+k-1]);
                        y.push_back(grid[row][c+k-1]);
                    }
                    sort(v.begin(), v.end());
                    for(int i = 0; i< v.size()-1; i++)
                    {
                        
                        if(v[i] == v[i+1])
                        {
                            int j = i+1;
                            while(j< v.size() && v[i] == v[j])
                            {
                                j++;
                            }
                            if(j== v.size())
                            {
                                break;
                            }
                            ans1 = min(ans1, abs(v[i]-v[j]));
                            i=j-1;
                        }
                        else
                        {
                            ans1 = min(ans1, abs(v[i]-v[i+1]));
                        }
                    }
                    if(ans1==INT_MAX)
                    {
                        ans[r][c] = 0;
                    }
                    else
                        ans[r][c] = ans1;
                }

            }
        }
        return ans; 

        
    }
};