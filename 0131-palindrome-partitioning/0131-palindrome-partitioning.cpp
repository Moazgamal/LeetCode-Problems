class Solution {
    bool isPalindrome(string &s, int start, int end, 
    vector<vector<int>>&dp)
    {
        
        if(start > end)
            return true;
        auto &ret = dp[start][end];
        if(ret != -1)
            return ret; 
        if(start == end)
            return ret = true;
        if(s[start] != s[end])
            return ret = false;
        return dp[start][end]= isPalindrome(s, start+1, end-1, dp);
    }
    void fn(int idx, vector<vector<int>>&v, vector<string>&acc,
     vector<vector<string>>&ans, string &s)
    {
        if(idx == v.size())
        {
            ans.push_back(acc);
            return; 
        }
        for(int i = 0; i< v[idx].size(); i++)
        {
            acc.push_back(s.substr(idx, v[idx][i]-idx+1));
            fn(v[idx][i]+1, v, acc, ans, s);
            acc.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {

        vector<vector<int>>v(s.size());
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));

        for(int i = s.size()-1; i>=0; i--)
        {
            for(int j = i; j< s.size(); j++)
            {
                if(s[i] != s[j])
                    continue;
                if(i == j)
                {
                    dp[i][j] = true; v[i].push_back(j); continue;
                }
                if(i-j == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true; v[i].push_back(j); continue;
                    }
                    else
                    {
                        dp[i][j] = false; continue;
                    }
                }
                if(i-j == 2)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true; v[i].push_back(j); continue;
                    }
                    else
                    {
                        dp[i][j] = false; continue;
                    }
                }
                if(isPalindrome(s, i, j,dp))
                {
                    v[i].push_back(j);
                }
            }
        }
        vector<vector<string>>ans; vector<string>acc;
        fn(0, v, acc, ans, s); return ans;


        
    }
};