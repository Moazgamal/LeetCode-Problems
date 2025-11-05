class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r< n ; r++)
        {
            unordered_map<int,bool>mp;
            int cnt = 0; 
            for(int c = 0; c< n; c++)
            {
                if(mp.count(matrix[r][c]) == 0)
                {
                    cnt++;
                    mp[matrix[r][c]]= true;
                }
            }
            if(cnt != n)
                return false; 
        }
        for(int r = 0; r< n ; r++)
        {
            unordered_map<int,bool>mp;
            int cnt = 0; 
            for(int c = 0; c< n; c++)
            {
                if(mp.count(matrix[c][r]) == 0)
                {
                    cnt++;
                    mp[matrix[c][r]]= true;
                }
            }
            if(cnt != n)
                return false; 
        }
        return true; 
    }
};