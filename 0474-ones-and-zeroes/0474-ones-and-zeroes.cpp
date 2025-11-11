class Solution {
    int fn(int idx, vector<pair<int,int>>&v, vector<vector<vector<int>>>&dp, int curM, int curN,
    int &m, int &n)
    {
        if(idx == v.size())
        {
            return 0; 
        }
        auto &ret = dp[idx][curM][curN];
        if(ret != -1)
            return ret;
        int ones = v[idx].second; int zeros = v[idx].first;
        int c1 = 0;
        if(curM + zeros <= m && curN+ ones <= n)
        {
            c1 = 1+ fn(idx+1, v, dp, curM+zeros, curN+ones, m, n);
        }
        int c2 = fn(idx+1, v, dp, curM, curN, m, n);
        return ret = max(c1, c2);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int,int>>v;
        for(int i = 0; i< strs.size(); i++)
        {
            int ones = 0; int zeros = 0; 
            for(int j = 0; j< strs[i].size(); j++)
            {
                if(strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            }
            v.push_back({zeros, ones});
        }
        vector<vector<vector<int>>>dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return fn(0, v, dp, 0, 0, m, n);
        
    }
};