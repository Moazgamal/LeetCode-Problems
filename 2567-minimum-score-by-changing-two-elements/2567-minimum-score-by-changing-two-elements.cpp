class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3)
            return 0;
        
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        ans = min(ans, abs(nums[nums.size()-2]-nums[1]));
        ans = min(ans, abs(nums[0]-nums[nums.size()-3]));
        ans = min(ans, abs(nums[2]-nums[nums.size()-1]));
        return ans; 
    }
};