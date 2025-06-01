class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();
        if(rows == cols)
        {
            vector<vector<int>> ans(rows-k+1, vector<int>(cols-k+1)); 
            int ans1 = 0; 
            bool f = true;
            vector<int> v;
            for(int r = 0; r< rows; r++)
                {
                    for(int c = 0; c< cols; c++)
                        {
                            v.push_back(grid[r][c]);
                        }
                }
            sort(v.begin(), v.end());
            for(int i = 0; i< v.size()-1; i++)
                {
                    if(f)
                            {
                                if(v[i] != v[i+1])
                                {
                                    int j = i+1;
                                    while(j< v.size() && v[i] == v[j])
                                        {
                                            j++;
                                        }
                                    if(j== v.size())
                                    {
                                        i= j; break;
                                    }
                                    ans1 = abs(v[i]-v[j]);
                                    i=j-1;
                                    f= false;
                                }
                            }
                            else
                            {
                                int j = i+1;
                                while(j< v.size() && v[i] == v[j])
                                    {
                                        j++;
                                    }
                                if(j == v.size())
                                {
                                    i = j; 
                                    break;
                                }
                                i=j-1;
                                
                                    ans1 = min(ans1, abs(v[i]-v[j]));
                            }
                }
            ans[0][0]=(ans1);
            if(k == 1)
                ans[0][0] = 0;
            return ans;
        }
        else if(rows < cols)
        {
            vector<int> v; 
            for(int c = 0; c< cols-rows+1; c++)
                {
                    for(int r = 0; r< rows; r++)
                        {
                            v.push_back(grid[r][c]);
                        }
                }
            vector<int> y = v;
            sort(v.begin(), v.end());
            reverse(y.begin(), y.end());
            int ans1 = 0; 
            vector<vector<int>> ans(rows-k+1, vector<int>(cols-k+1));
            bool f = true; 
            for(int i = 0; i< v.size()-1; i++)
                {
                    if(f)
                            {
                                if(v[i] != v[i+1])
                                {
                                    int j = i+1;
                                    while(j< v.size() && v[i] == v[j])
                                        {
                                            j++;
                                        }
                                    if(j== v.size())
                                    {
                                        i= j; break;
                                    }
                                    ans1 = abs(v[i]-v[j]);
                                    i=j-1;
                                    f= false;
                                }
                            }
                            else
                            {
                                int j = i+1;
                                while(j< v.size() && v[i] == v[j])
                                    {
                                        j++;
                                    }
                                if(j == v.size())
                                {
                                    i = j; 
                                    break;
                                }
                                
                                i=j-1;
                                    ans1 = min(ans1, abs(v[i]-v[j]));
                            }
                }
            if(k==1)
                ans[0][0] = 0;
            else
                ans[0][0] = (ans1);
            int newCol = rows;
            int t = 1;
            while(newCol < cols)
                {
                    ans1= 0; 
                    f = true;
                    int cnt = rows;
                    while(cnt--)
                        {
                            y.pop_back();
                        }
                    reverse(y.begin(), y.end());
                    for(int j = 0; j< rows; j++)
                        {
                            y.push_back(grid[j][newCol]);
                        }
                    v = y;
                    sort(v.begin(), v.end());
                   
                    for(int i = 0; i< v.size()-1; i++)
                        {
                            if(f)
                            {
                                if(v[i] != v[i+1])
                                {
                                    int j = i+1;
                                    while(j< v.size() && v[i] == v[j])
                                        {
                                            j++;
                                        }
                                    if(j== v.size())
                                    {
                                        i= j; break;
                                    }
                                    ans1 = abs(v[i]-v[j]);
                                    i=j-1;
                                    f= false;
                                }
                            }
                            else
                            {
                                int j = i+1;
                                while(j< v.size() && v[i] == v[j])
                                    {
                                        j++;
                                    }
                                if(j == v.size())
                                {
                                    i = j; 
                                    break;
                                }
                                i=j-1;
                                
                                    ans1 = min(ans1, abs(v[i]-v[j]));
                            }
                        }
                    reverse(y.begin(), y.end());
                    if(k == 1)
                        ans[0][t++] = 0;
                    else
                        ans[0][t++] = (ans1);
                    newCol++;
                }
            return ans; 
        }
        else
        {
            vector<int> v; 
            for(int r = 0; r< rows-cols+1; r++)
                {
                    for(int c = 0; c< cols; c++)
                        {
                            v.push_back(grid[r][c]);
                        }
                }
            vector<int> y = v;
            sort(v.begin(), v.end());
            reverse(y.begin(), y.end());
            int ans1 = 0; 
            vector<vector<int>> ans(rows-k+1, vector<int>(cols-k+1));
            bool f = true; 
            for(int i = 0; i< v.size()-1; i++)
                {
                    if(f)
                            {
                                if(v[i] != v[i+1])
                                {
                                    int j = i+1;
                                    while(j< v.size() && v[i] == v[j])
                                        {
                                            j++;
                                        }
                                    if(j== v.size())
                                    {
                                        i= j; break;
                                    }
                                    ans1 = abs(v[i]-v[j]);
                                    i=j-1;
                                    f= false;
                                }
                            }
                            else
                            {
                                int j = i+1;
                                while(j< v.size() && v[i] == v[j])
                                    {
                                        j++;
                                    }
                                if(j == v.size())
                                {
                                    i = j; 
                                    break;
                                }
                                
                                i = j-1;
                                    ans1 = min(ans1, abs(v[i]-v[j]));
                            }
                }
            if(k==1)
                ans[0][0] = 0;
            else
                ans[0][0]=(ans1);
            int newRow = cols;
            int t  = 1; 
            while(newRow < rows)
                {
                    f = true; 
                    ans1 = 0; 
                    int cnt = cols;
                    while(cnt--)
                        {
                            y.pop_back();
                        }
                    reverse(y.begin(), y.end());
                    for(int j = 0; j< cols; j++)
                        {
                            y.push_back(grid[newRow][j]);
                        }
                    v = y;
                    sort(v.begin(), v.end());
                   
                    for(int i = 0; i< v.size()-1; i++)
                        {
                             if(f)
                            {
                                if(v[i] != v[i+1])
                                {
                                    int j = i+1;
                                    while(j< v.size() && v[i] == v[j])
                                        {
                                            j++;
                                        }
                                    if(j== v.size())
                                    {
                                        i= j; break;
                                    }
                                    ans1 = abs(v[i]-v[j]);
                                    i=j-1;
                                    f= false;
                                }
                            }
                            else
                            {
                                int j = i+1;
                                while(j< v.size() && v[i] == v[j])
                                    {
                                        j++;
                                    }
                                if(j == v.size())
                                {
                                    i = j; 
                                    break;
                                }
                                i=j-1;
                                
                                    ans1 = min(ans1, abs(v[i]-v[j]));
                            }
                        }
                    reverse(y.begin(), y.end());
                    if(k==1)
                        ans[t++][0] =0;
                    else
                        ans[t++][0] = (ans1);
                    newRow++;
                }
            return ans; 
        }
        return {}; 
            
        
    }
};