class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i< numRows; i++)
        {
            vector<int> v(i+1,1);
            if(i >= 2)
            {
                for(int c = 1; c< i; c++)
                {
                    v[c] = ans[i-1][c]+ ans[i-1][c-1];
                }
            }
            ans[i]=v;
        }
        return ans; 
        
    }
};