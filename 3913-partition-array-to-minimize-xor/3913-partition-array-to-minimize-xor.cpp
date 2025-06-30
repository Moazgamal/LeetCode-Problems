class Solution {
    
    int fn(int idx, vector<int>&nums, int k, vector<long long>&v, vector<vector<long long>>&dp,
    int &ans)
    {
        if(idx == nums.size())
        {
            if(k ==0)
                return 0 ; 
            return INT_MAX;
        }
        if(k==0 && idx<nums.size())
            return INT_MAX;
       if(k==1)
       {
            return v[idx];
       }
        auto &ret = dp[idx][k];
        if(ret != -1)
            return ret; 
        long long acc = 0; 
        ret = INT_MAX;
        for(int i = idx; i< nums.size(); i++)
        {
            acc ^= nums[i];
            long long val = INT_MAX;
            
                val = fn(i+1, nums, k-1, v, dp, ans);
                val = max(val, acc);
                ret = min(ret, val);
            
        }
        return ret; 
        
    }
public:
    int minXor(vector<int>& nums, int k) {
        
        int total = 0;
        for(auto x: nums)
            total ^= x;
        vector<long long> v(nums.size(),0);
        for(int i = 0; i<nums.size();i++)
        {
            if(i==0)
                v[i] = total;
            else
            {
                v[i] = total^nums[i-1];
                total ^= nums[i-1];
            }
        }
        if(nums.size()==1)
            return nums[0];
        vector<vector<long long>>dp(nums.size()+1, vector<long long>(k+1,-1));
        int ans = INT_MAX; 
         return fn(0, nums, k, v, dp, ans);
         return ans; 
        
    }
};