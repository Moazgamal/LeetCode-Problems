class Solution {
    int fn(int start, int end, vector<int>&nums, vector<vector<int>>&dp)
    {
        // if(start == end)
        //     return nums[start];
        if(start > end )
            return 0; 
        auto &ret = dp[start][end];
        if(ret != -1)
            return ret; 
        for (int k = start; k <= end; k++) 
        {
            int action = nums[start - 1] * nums[k] * nums[end + 1];
            // Now K should be fixed and next sub-calls don't use our LAST baloon
            int sub1 = fn(start, k - 1,nums,dp);
            int sub2 = fn(k + 1, end,nums,dp);
            int total_k = action + sub1 + sub2; 
            ret = max(ret, total_k);
	    }
	return ret;
    }
public:
    int maxCoins(vector<int>& nums) {

        vector<int>v(1,1);
        for(auto x: nums)
            v.push_back(x);
        v.push_back(1);
        vector<vector<int>>dp(303, vector<int>(303, -1));
        cout<<v.size()<<"\n";
        return fn(1, v.size()-2, v, dp);
        
    }
};