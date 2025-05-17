class Solution {
    int LIS(int idx , vector<string> &words, vector<int> &groups, vector<int>&dp)
    {
        if(idx>= words.size())
            return 0; 
        auto &ret = dp[idx];
        if(ret != -1)
            return ret; 
        ret = 1; 
        for(int i = idx+1 ; i< words.size(); i++)
        {
            if(groups[idx] != groups[i])
            {
                if(words[idx].size() == words[i].size())
                {
                    int cnt = 0; 
                    for(int j = 0; j< words[idx].size(); j++)
                    {
                        if(words[idx][j] != words[i][j])
                        {
                            cnt++;
                            if(cnt>1)
                                break;
                        }
                    }
                    if(cnt == 1)
                    {
                        ret = max(ret, 1+LIS(i, words, groups,dp));
                    }
                    
                }
            }
        }
        return ret; 
    };
    
        
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        vector<string> ans;

        vector<int> dp(words.size(), -1);
        int res = 0; 
        for(int i = 0; i< words.size(); i++)
        {
           res = max(res, LIS(i, words, groups, dp) );
        }
        for(int i = 0; i< words.size(); i++)
        {
            if(dp[i] == res)
            {
                ans.push_back(words[i]);
                res--;
                int k = i+1;
                while(k<words.size())
                {
                    if(groups[i] != groups[k] && dp[k] == res)
                    {
                        if(words[i].size() == words[k].size())
                        {
                            int cnt = 0; 
                            for(int j = 0; j< words[i].size(); j++)
                            {
                                if(words[i][j] != words[k][j])
                                {
                                    cnt++;
                                    if(cnt>1)
                                        break;
                                }
                            }
                            if(cnt == 1)
                            {
                                ans.push_back(words[k]);
                                res--;
                                i= k ;
                            }
                        }
                    }
                    k++;
                }
                break;
            }
        }
       
        return ans; 
        
        
    }
};