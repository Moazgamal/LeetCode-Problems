class Solution {
    
    int fn(int r, int c , vector<vector<int>>&dun, vector<vector<int>>&dp)
    {
        if(r<0 || c<0 || r>= dun.size() || c>=dun[0].size())
            return INT_MAX/2;
        
        auto &ret = dp[r][c];
        if(ret != -1)
            return ret;
        if(r== dun.size()-1 && c == dun[0].size()-1)
        {
           if(dun[r][c]>=0)
                return ret = 0;
            return ret =  (-dun[r][c]);
        }
        
        int c1 =  fn(r+1,c, dun, dp);
        int c2 = fn(r,c+1,dun,dp);
            
       int minicost = -dun[r][c] + min(c1,c2);
       if(minicost >0)
        return ret = minicost;
        return ret = 0;
        
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
        fn(0,0, dungeon, dp);
        if(dp[0][0]<=0)
            return 1;
        return dp[0][0]+1;
        
    }
};