class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int ans = 0; 
        vector<int>row(mat.size(),0);
        vector<int>cols(mat[0].size());
        for(int r = 0; r< mat.size(); r++)
        {
            for(int c = 0; c< mat[0].size(); c++)
            {
                if(mat[r][c] == 1)
                {
                    row[r]++;
                    cols[c]++;
                }
            }
        }
        for(int r = 0; r< mat.size(); r++)
        {
            if(row[r]>1)
                continue;
            for(int c = 0; c< mat[0].size(); c++)
            {
                if(mat[r][c] == 1 && cols[c] == 1 && row[r] == 1)
                {
                    ans++; break;
                }
            }
        }
        return ans;
    }
};