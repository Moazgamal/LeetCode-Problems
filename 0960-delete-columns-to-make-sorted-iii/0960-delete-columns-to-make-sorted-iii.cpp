class Solution {
    bool compareStrings(string &s1, string &s2)
    {
        for(int i = 0; i< s2.size(); i++)
            if(s2[i] < s1[i])
                return false; 
        return true; 
    }
    int fn(int curIdx, int prev, vector<string>&v, vector<vector<int>>&dp)
    {
        if(curIdx >= v.size())
            return 0; 
        auto &ret = dp[curIdx][prev];
        if(ret != -1)
            return ret; 
        int c1 = 0; 
        if(prev == v.size() || compareStrings(v[prev], v[curIdx]))
            c1 = 1+ fn(curIdx+1, curIdx, v, dp);
        int c2 = fn(curIdx+1, prev, v, dp);

        return ret = max(c1, c2);
    }
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string>v;
        for(int i =0; i< strs[0].size(); i++)
        {
            string str = "";
            for(int j = 0; j< strs.size(); j++)
                str.push_back(strs[j][i]);
            v.push_back(str);
        }
        vector<vector<int>>dp(v.size()+1, vector<int>(v.size()+1, -1));
        int jj = fn(0, v.size(),v,dp);
        return (int)v.size()-fn(0, v.size(),v,dp);
        
    }
};