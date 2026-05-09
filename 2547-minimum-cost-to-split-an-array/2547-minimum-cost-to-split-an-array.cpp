class Solution {
    int fn(int idx, vector<int>&nums, int &k, vector<int> &dp)
    {
        if(idx==nums.size())
            return 0;
        auto &ret = dp[idx];
        if(ret != INT_MAX)
            return ret; 
        unordered_map<int,int>mp;
        int len=0;
        for(int i = idx; i< nums.size(); i++)
        {
            if(mp.count(nums[i]) == 0)
            {
                mp[nums[i]]=1;
                ret = min(ret, len+k+fn(i+1, nums,k, dp));
            }
            else
            {
                if(mp[nums[i]]==1)
                    len+=2;
                else
                    len++;

                mp[nums[i]]++;
                ret = min(ret, len+k+fn(i+1, nums,k, dp));
            }
        }
        return ret;
    }
public:
    int minCost(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),INT_MAX);
        fn(0, nums, k, dp);
        return dp[0];
    }
};