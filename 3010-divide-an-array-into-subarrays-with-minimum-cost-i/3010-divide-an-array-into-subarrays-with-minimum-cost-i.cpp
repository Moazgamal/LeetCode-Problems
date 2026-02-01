class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int ans = nums[0];
        int mini2 = INT_MAX; int mini3 = INT_MAX;
        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i] <= mini2)
            {
                mini3 = mini2;
                mini2 = nums[i];
            }
            else if(nums[i] < mini3)
                mini3 = nums[i];
        }
        return ans + mini2 + mini3;
        
    }
};