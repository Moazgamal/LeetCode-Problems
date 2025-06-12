class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0]-nums[1]);
        for(int i = 1; i< nums.size()-1; i++)
            {
                ans = max(ans,abs(nums[i]-nums[i+1]));
            }
        ans = max(ans, abs(nums[nums.size()-1]-nums[0]));
        return ans;
        
    }
};