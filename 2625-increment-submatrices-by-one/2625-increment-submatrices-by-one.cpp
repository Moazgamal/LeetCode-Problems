class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>v(n+1, vector<int>(n+1, 0));
        for(int i = 0; i< queries.size(); i++)
        {
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];
            for(int j = row1; j<= row2; j++)
            {
                v[j][col1]++; v[j][col2+1]--;
            }
        }
        vector<vector<int>>ans(n, vector<int>(n, 0));
        for(int r = 0; r< n; r++)
        {
            int acc = 0; 
            for(int c = 0; c< n; c++)
            {
                acc += v[r][c];
                ans[r][c] = acc; 
            }
        }return ans; 
        
    }
};