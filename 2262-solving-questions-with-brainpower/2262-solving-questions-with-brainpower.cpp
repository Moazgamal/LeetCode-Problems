class Solution {
    long long fn(int idx, vector<vector<int>>&q, vector<long long> &dp)
    {
        if(idx>= q.size())
            return 0; 
        auto &ret = dp[idx] ;
        if(ret != -1)
            return ret;
        long long pick = q[idx][0] + fn(idx+q[idx][1]+1, q, dp);
        long long leave = fn(idx+1, q, dp);
        return ret = max(pick , leave);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return fn(0,questions,dp);
        
    }
};