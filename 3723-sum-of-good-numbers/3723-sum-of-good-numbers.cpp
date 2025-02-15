class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
            {
                if(i-k >=0)
                {
                    if(nums[i-k] >= nums[i])
                        continue;
                }
                if(i+k<nums.size())
                {
                    if(nums[i+k]>=nums[i])
                        continue;
                }
                ans+=nums[i];
            }return ans;
        
    }
};