class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        for(int c = 0; c< mat[0].size(); c++)
        {
            vector<int>collect;
            int r = 0; int col = c;
            while(r>=0 && r< mat.size() && col>=0 && col< mat[0].size())
            {
                collect.push_back(mat[r][col]);
                r++; col++;
            }
            r = 0; col = c; 
            int i = 0; 
            sort(collect.begin(), collect.end());
            while(r>=0 && r< mat.size() && col>=0 && col< mat[0].size())
            {
                mat[r][col] = collect[i++];
                r++; col++;
            }
        }
        for(int r = 0; r< mat.size(); r++)
        {
            vector<int>collect;
            int c = 0; int row = r;
            while(c>=0 && c< mat[0].size() && row>=0 && row< mat.size())
            {
                collect.push_back(mat[row][c]);
                row++; c++;
            }
            row = r; c = 0; 
            int i = 0; 
            sort(collect.begin(), collect.end());
            while(row>=0 && row< mat.size() && c>=0 && c< mat[0].size())
            {
                mat[row][c] = collect[i++];
                row++; c++;
            }
        }
        
        return mat;

        
    }
};