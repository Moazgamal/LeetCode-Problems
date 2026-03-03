class Solution {
    bool fn(int idx1, int idx2, int idx3, string &s1,
    string &s2, string &s3, vector<vector<int>>&dp)
    {
        if(idx3 == s3.size())
            return true;
        auto &ret = dp[idx1][idx2];
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        for(int i = idx1; i < s1.size(); i++)
        {
            if(s1.substr(idx1, i-idx1+1) ==
            s3.substr(idx3, i-idx1+1))
            {
                if(idx3+(i-idx1+1) == s3.size())
                    return ret = true;
                if(s2[idx2] == s3[idx3+(i-idx1+1)])
                {
                    for(int j = idx2; j< s2.size(); j++)
                    {
                        if(s2.substr(idx2, j-idx2+1) ==
                            s3.substr(idx3+(i-idx1+1), j-idx2+1))
                        {
                            bool choice = fn(i+1, j+1, idx3+(i-idx1+1)+j-idx2+1, s1, s2, s3, dp);
                            if(choice)
                                return ret = true; 
                        }
                        else
                            break;
                    }
                }
                else
                    continue;
            }
            else
                return ret = false;
        }
        return ret = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() > s3.size())
            return false;
        vector<vector<int>>dp(s3.size()+1, vector<int>(s3.size()+1, -1));
        bool c1 =  fn(0, 0, 0, s1, s2, s3, dp);
        if(c1)
            return c1;
        vector<vector<int>>dp2(s3.size()+1, vector<int>(s3.size()+1, -1));
        
        return fn(0, 0, 0, s2, s1, s3, dp2);
    }
};