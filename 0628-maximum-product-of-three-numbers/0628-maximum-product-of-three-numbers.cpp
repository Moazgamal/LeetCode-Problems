class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        ans = max(ans, nums[0]*nums[1]*nums[nums.size()-1]);
        ans = max(ans, nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
        return ans; 
        
    }
};