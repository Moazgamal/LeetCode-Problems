class Solution {
    bool fn(int idx, vector<int> &nums, vector<vector<int>>&dp, int totalsum, int &sum)
    {
        if(idx >= nums.size())
        {
            if(totalsum*2== sum)
                return true;
            return false;
        }
        int ret = dp[idx][totalsum];
        if(ret != -1)
            return ret;
        int pick = fn(idx+1, nums, dp, totalsum-nums[idx],sum);
        if(pick == true)
            return dp[idx][totalsum] = true;
        return dp[idx][totalsum] = fn(idx+1, nums, dp, totalsum,sum);
        
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            totalsum += nums[i];
        }
        vector<vector<int>>dp(nums.size()+1, vector<int>(totalsum+1,-1));
       
        return fn(0, nums, dp,totalsum, totalsum);

        
    }
};