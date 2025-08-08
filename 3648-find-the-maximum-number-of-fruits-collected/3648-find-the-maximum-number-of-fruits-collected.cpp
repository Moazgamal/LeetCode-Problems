class Solution {
    bool isvalid(int r, int c, vector<vector<int>>&f)
    {
        if(r<0 || c<0 || r>= f.size() || c>= f.size())
            return false;
        return true;
    }
    int fn1(int r, int c, vector<vector<int>>&f, vector<vector<int>>&dp)
    {
        auto &ret = dp[r][c];
        if(ret != -1)
            return ret; 
        ret = f[r][c];
        int row= r+1; int col = c-1;
        if(isvalid(row,col,f) && col>=row)
        {
            ret =max(ret , f[r][c]+fn1(row, col, f, dp));
        }
        row = r+1; col = c;
        if(isvalid(row, col, f) && col>=row)
        {
            ret = max(ret, f[r][c]+fn1(row, col, f,dp));
        }
        row = r+1; col=c+1;
         if(isvalid(row, col, f) && col>=row)
        {
            ret = max(ret, f[r][c]+fn1(row, col, f,dp));
        }
        return ret; 
    }
    int fn2(int r, int c, vector<vector<int>>&f, vector<vector<int>>&dp)
    {
        auto &ret = dp[r][c];
        if(ret != -1)
            return ret; 
        ret = f[r][c];
        int row= r-1; int col = c+1;
        if(isvalid(row,col,f) && row>=col)
        {
            ret =max(ret , f[r][c]+fn2(row, col, f, dp));
        }
        row = r; col = c+1;
        if(isvalid(row, col, f) && row>=col)
        {
            ret = max(ret, f[r][c]+fn2(row, col, f,dp));
        }
        row = r+1; col = c+1;
        if(isvalid(row, col, f) && row>=col)
        {
            ret = max(ret, f[r][c]+fn2(row, col, f,dp));
        }
        return ret; 
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int r = 0; int c = 0;
        int ans  = 0; 
        while(r< fruits.size() && c < fruits.size())
        {
            cout<<fruits[r][c]<<" ";
            ans += fruits[r][c];
            fruits[r][c] = 0; 
             r++; c++;
        }
        cout<<"\n";
        r = 0; c = fruits.size()-1;
        vector<vector<int>>dp(fruits.size(), vector<int>(fruits.size(),-1));
        ans += fn1(r, c, fruits, dp);
        r = fruits.size()-1; c = 0; 
        vector<vector<int>>dp2(fruits.size(), vector<int>(fruits.size(),-1));

        ans+= fn2(r, c, fruits, dp2);
        cout<<dp[0][fruits.size()-1]<<" "<<dp2[fruits.size()-1][0]<<"\n";

        return ans; 
    }
};