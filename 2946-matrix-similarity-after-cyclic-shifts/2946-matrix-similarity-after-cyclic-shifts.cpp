class Solution {
    bool fn1(int r, vector<vector<int>>&mat, int k)
    {
        // even
        int i = 0; 
        int j = k;
        while(i < mat[0].size())
        {
            if(mat[r][i] != mat[r][j])
                return false;
            i++;
            j++;
            j %= mat[0].size();
        }
        return true; 
    }
    bool fn2(int r, vector<vector<int>>&mat, int k)
    {
        // even
        int i = 0; 
        int j = mat[0].size()-k;
        while(i < mat[0].size())
        {
            if(mat[r][i] != mat[r][j])
                return false;
            i++;
            j++;
            j %= mat[0].size();
        }
        return true; 
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        k = k%mat[0].size();
        if(k  == 0)
            return true;
        bool turn = false;
        for(int r = 0; r< mat.size(); r++)
        {
            if(turn==false)
            {
                if(fn1(r, mat, k)==false)
                    return false;
            }
            else
            {
                if(fn2(r, mat, k)==false)
                    return false;
            }
            turn = !turn;
        }
        return true; 

    }
};