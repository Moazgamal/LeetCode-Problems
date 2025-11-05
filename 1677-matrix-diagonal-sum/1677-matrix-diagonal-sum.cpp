class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0; 
        for(int r = 0; r< mat.size(); r++)
            for(int c = 0; c< mat.size(); c++)
                if(r == c || r+c == mat.size()-1)
                    ans+=mat[r][c];
        return ans; 

        
    }
};