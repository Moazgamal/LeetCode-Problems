class Solution {
    int fn(int idx, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(target==0)
            return 0;
        if(target<0)
            return INT_MIN/2;
        if(idx>=nums.size())
            return INT_MIN/2;
        auto &ret = dp[idx][target];
        if(ret != -1)
            return ret;
        int ans = INT_MIN/2;
       int c1= 1+fn(idx+1, nums, target-nums[idx], dp);
        int c2 = fn(idx+1, nums, target, dp);
        return ret = max(ans, max(c1, c2));
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        vector<vector<int>>dp(nums.size()+1, vector<int>(target+1,-1));
        return fn(0, nums, target, dp) >0? dp[0][target] : -1;
    }
};