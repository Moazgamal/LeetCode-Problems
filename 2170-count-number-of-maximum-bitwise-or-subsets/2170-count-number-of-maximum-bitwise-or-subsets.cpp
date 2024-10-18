class Solution {
    void fn(int idx, int prev, vector<int>&nums,  int &maxi, int &ans)
    {
        if(idx>=nums.size())
        {
            if(prev == maxi)
                ans++;
            return ;
        }
        
        if(prev == 0)
        {
            fn(idx+1, nums[idx], nums,  maxi,ans);
           fn(idx+1, prev, nums,maxi,ans);
        }
        else
        {
           fn(idx+1, prev, nums, maxi,ans);
          fn(idx+1, prev|nums[idx],nums, maxi,ans);
        }
        
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            maxi |= nums[i];
        }
        int ans  =0; 
         fn(0,0,nums, maxi, ans);
         return ans;
        
    }
};