class Solution {
    int fn(int idx, vector<int>&s, vector<vector<int>>&dp, int prev)
    {
        if(idx >= s.size())
            return 0; 
        auto &ret = dp[idx][prev];
        if(ret != -1)
            return ret; 
        int c1 = prev*s[idx] + fn(idx+1, s, dp, prev+1);
        int c2 = fn(idx+1, s, dp, prev);
        return ret = max(c1, c2);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>>dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1,-1));
        return fn(0, satisfaction, dp, 1);
        
    }
};