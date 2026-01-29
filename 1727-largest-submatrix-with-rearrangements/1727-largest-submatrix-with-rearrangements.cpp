class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        vector<vector<int>>v(matrix.size(), vector<int>(matrix[0].size(),0));
        vector<vector<int>>v2(matrix.size());
        for(int c = 0; c< matrix[0].size(); c++)
        {
            for(int r = 0; r< matrix.size(); r++)
            {
                if(matrix[r][c] == 1)
                {
                    if(r-1>= 0)
                        v[r][c] = 1+ v[r-1][c];
                    else
                        v[r][c] = 1;
                    
                    v2[r].push_back(c);
                }
            }
        }
        int ans = 0; 
        for(int r = matrix.size()-1; r >= 0; r--)
        {
            if(v2[r].size() == 0)
                continue;
            vector<int>collect;
            for(int j = 0; j< v2[r].size(); j++)
                collect.push_back(v[r][v2[r][j]]);
            
            sort(collect.begin(), collect.end());
            for(int m = 0; m< collect.size(); m++)
                ans = max(ans, (collect[m]*((int)collect.size()-m)));
        }
        return ans; 
        
    }
};