class Solution {
    
    int fn(int idx, vector<int>&nums, int k, vector<int>&v, vector<vector<int>>&dp)
    {
        if(idx == (int)nums.size())
        {
            if(k ==0)
                return 0 ; 
            return INT_MAX;
        }
        if(k==0 && idx<(int)nums.size())
            return INT_MAX;
       if(k==1)
       {
            return v[idx];
       }
        auto &ret = dp[idx][k];
        if(ret != -1)
            return ret; 
        int acc = 0; 
        ret = INT_MAX;
        for(int i = idx; i< (int)nums.size(); i++)
        {
            acc ^= nums[i];
            int val = INT_MAX;
            
            val = fn(i+1, nums, k-1, v, dp);
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
        vector<int> v((int)nums.size(),0);
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
        if((int)nums.size()==1)
            return nums[0];
        vector<vector<int>>dp((int)nums.size()+1, vector<int>(k+1,-1));
        
         return fn(0, nums, k, v, dp);
        
        
    }
};