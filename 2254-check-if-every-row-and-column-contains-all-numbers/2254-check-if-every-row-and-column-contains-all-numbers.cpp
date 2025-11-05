class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r< n ; r++)
        {
            vector<bool>mp(n+1,false);
            int cnt = 0; 
            for(int c = 0; c< n; c++)
            {
                if(mp[matrix[r][c]]== false)
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
            vector<bool>mp(n+1,false);
            int cnt = 0; 
            for(int c = 0; c< n; c++)
            {
                if(mp[matrix[c][r]]== false)
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