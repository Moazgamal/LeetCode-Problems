class Solution {
    bool compareStrings(string &s1, string &s2)
    {
        for(int i = 0; i< s2.size(); i++)
            if(s2[i] < s1[i])
                return false; 
        return true; 
    }
    int fn(int curIdx, vector<string> &v, vector<int> &dp)
    {
        if(curIdx >= v.size())
            return 0; 
        auto &ret = dp[curIdx];
        if(ret != -1)
            return ret; 

        ret = 1; 
        for(int i = curIdx+1; i< v.size(); i++)
            if(compareStrings(v[curIdx], v[i]))
                ret = max(ret, 1+fn(i, v, dp));
                
        return ret;
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
        vector<int>dp(v.size()+1, -1);
        int maxi = 0; 
        for(int i = 0; i< v.size(); i++)
        {
            if(dp[i] != -1)
                continue;
            maxi = max(maxi, fn(i, v, dp));
        }
        return (int)v.size()-maxi;
        
    }
};