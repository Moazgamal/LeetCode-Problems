class Solution {
    const int MOD = 1e9+7;
    int fn(int idx, vector<int>&nums, vector<vector<int>>&dp, int prev1, int prev2)
    {
        if(idx == nums.size())
            return 1; 

        auto &ret = dp[idx][prev1];
        if(ret != -1)
            return ret; 
        
        ret  = 0; 
        for(int i = prev1; i<= nums[idx]; i++)
        {
            if(nums[idx]-i <=prev2)
                ret += fn(idx+1, nums, dp, i, nums[idx]- i);
            ret %= MOD;
        }
        return ret; 
    }
public:
    int countOfPairs(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(52, -1));
        int ans = 0; 
        return fn(0, nums, dp, 0, 51); 
    }
};