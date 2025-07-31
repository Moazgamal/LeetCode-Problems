class Solution {
    int fn(int row, vector<vector<int>>&v, set<int>&st, int cur, int real,
    int n)
    {
        if(row == n-1)
            return 0 ;
        int steps = INT_MAX/2;
        for(int i = 0; i< v[row].size(); i++)
        {
            int srow= v[row][i];
            if(st.find(srow) != st.end())
            {
                auto it = st.find(srow);
                int index = std::distance(st.begin(), it);
                st.erase(srow);
                int steps2 = fn(row+1, v, st, cur, real+1, n);
                if(steps2 != INT_MAX/2)
                {
                    return index +steps2;
                }
                st.insert(srow);
            }
            // else if(srow == row || cur == srow)
            // {
            //     vis[srow] = true;
            //     for(int i = 0; i< vis.size(); i++)
            //     {
            //         if(!vis[i])
            //         {
            //             int steps2 = fn(row+1, v, vis, i, real+1,n);
            //             if(steps2 != INT_MAX/2)
            //                 return steps2;
            //             break;
            //         }
            //     }
            //     vis[srow]= false;
            // }
        }
        return steps; 
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1)
            return -1;
        vector<vector<int>> v(n-1);
        for(int r = n-1; r>=0; r--)
        {
            int x = n-2;
            for(int c = n-1; c>=1; c--)
            {
                if(grid[r][c] == 1)
                {
                    break;
                }
                else
                {
                    v[x].push_back(r); x--;
                }
            }
        }
        for(int r = 0; r<= n-2; r++)
        {
            if(v[r].size() == 0)
                return -1; 
            sort(v[r].begin(), v[r].end());
        }
        set<int>st;
        for(int i = 0; i< n; i++)
        {
            st.insert(i);
        }
        int ans =  fn(0, v, st, 0, 0,n);
        if(ans>=INT_MAX/2)
            return -1;
        return ans; 

        
    }
};