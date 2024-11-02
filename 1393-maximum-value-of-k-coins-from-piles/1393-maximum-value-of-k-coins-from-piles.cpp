class Solution {

    int fn(int idx, vector<vector<int>>&piles, vector<vector<int>>&dp, int k)
    {
        if(k==0)
            return 0; 
        if(idx>= piles.size())
            return 0;
        auto &ret = dp[idx][k];
        if(ret != -1)
            return ret;
        int ans = 0;
        int _k = k;
        
            
            int j =0;
            int sum = 0; 
            while(j<piles[idx].size() && _k>0)
            {
                _k--;
                sum+=piles[idx][j];
                if(_k==0)
                    ans= max(ans,sum);
                else
                    ans = max(ans, sum+fn(idx+1, piles, dp, _k));
                j++;
            }
            ans = max(ans, fn(idx+1, piles, dp, k));
        
        return ret = ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(), vector<int>(k+1, -1));

        return fn(0, piles, dp, k);
        
    }
};