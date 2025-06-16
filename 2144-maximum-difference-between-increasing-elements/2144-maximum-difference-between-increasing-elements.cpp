class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = nums[0];
        int ans = -1;
        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i]>maxi)
                ans = max(ans, nums[i]-maxi);
            maxi = min(maxi, nums[i]);
        }
        return ans; 
    }
};