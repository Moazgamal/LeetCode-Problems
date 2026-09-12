class Solution {
    int MOD = 1e9+7;
    int fn(int IDX, vector<int>&Dp, vector<vector<int>>&v)
    {
        auto &ret = Dp[IDX];
        if(ret != -1)
            return ret; 
        ret = 1; 
        for(int i = 0; i< 26; i++)
        {
            if(v[IDX][i] == -1 || v[IDX][i] == IDX)
                continue;
            ret += fn(v[IDX][i], Dp, v);
            ret %= MOD;
        }
        return ret; 
    }
public:
    int distinctSubseqII(string s) {

        vector<vector<int>>v(s.size());

        vector<int>cur(26, -1);

        for(int i = s.size()-1; i >= 0; i--)
        {
            v[i] = cur;
            cur[s[i]-'a'] = i;
        }

        vector<int>Dp(s.size(), -1);

        int ans = 0; 
        
        for(int i = 0; i< 26; i++)
        {
            if(cur[i] != -1)
            {
                ans += fn(cur[i], Dp, v);
                ans %= MOD;
            }
        }

        return ans;
    }
};