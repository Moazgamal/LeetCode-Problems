class Solution {
    int fn(int idx, vector<int> &nums, int target, vector<int> &dp)
    {
        if(idx == nums.size()-1)
            return 0;
        auto &ret = dp[idx];
        
        if(ret != INT_MIN/2)
            return ret ; 
        for(int i = idx+1; i < nums.size(); i++)
        {
            if(nums[i]-nums[idx] >= (target*-1) && nums[i]-nums[idx]<=target)
            {
                ret = max(ret, 1+fn(i, nums, target, dp));
            }
        }
        return ret; 
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(), INT_MIN/2);
        fn(0, nums, target, dp);
        if(dp[0] < INT_MIN/4)
            return -1;
        return dp[0];
        
    }
};