class Solution {
    int fn1(int indx, vector<int>&nums, vector<int>&dp)
    {
        
        auto&ret = dp[indx];
        if(ret != 0)
            return ret;
        for(int i = indx+1; i<nums.size();i++)
        {
            if(nums[i] < nums[indx])
                ret = max(ret , 1+fn1(i,nums,dp));
        }
        return ret ;
    }
    int fn2(int indx, vector<int>&nums, vector<int>&dp2)
    {
        
        auto&ret = dp2[indx];
        if(ret != 0)
            return ret;
        if(indx<=0)
            return ret = 0; 
        for(int i = indx-1; i>=0; i--)
        {
            if(nums[i] < nums[indx])
                ret = max(ret , 1+fn2(i,nums,dp2));
        }
        
        return ret ;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        vector<int>dp2(nums.size(),0);
        for(int i =0; i< nums.size(); i++)
        {
            
                dp[i]=fn1(i,nums,dp);
            
        }
        for(int i =nums.size()-1; i>=0; i--)
        {
            
                dp2[i]=fn2(i,nums,dp2);
            
        }
        int ans = INT_MAX;
        int sz = nums.size();
        for(int i = 1; i< nums.size()-1; i++)
        {
            int val1 = dp[i];
            int val2 = dp2[i];
            if(val1 >0 && val2>0)
                ans = min(ans,sz-(val1+val2+1));
            
        }
        
        return ans;
        


        
    }
};