class Solution {
    int fn(int idx , vector<int>&nums, vector<vector<int>> &dp, int sum, int target)
    {
        if(idx >= nums.size())
        {
            
            if(target == sum+1000)
                return 1;
            return 0; 
        }
        
        auto &ret = dp[idx][sum+1000];
        if(ret != INT_MIN/2)
            return ret;
        
        int c1 = fn(idx+1, nums, dp, -nums[idx]+sum, target);
        int c2 = fn(idx+1, nums, dp, nums[idx]+sum, target);
        return ret = c1+c2;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size()+1, vector<int>(2000, INT_MIN/2));
        return fn(0, nums ,dp, 0, target+1000);
        
    }
};