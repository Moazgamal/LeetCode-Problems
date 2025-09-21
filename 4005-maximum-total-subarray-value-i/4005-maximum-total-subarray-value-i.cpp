class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0; 
        int maxi =nums[0]; int mini = nums[0];
        long long diff = maxi - mini; 
        ans = max(ans, diff);
        for(int i = 1; i< nums.size(); i++)
        {
            maxi = max(nums[i], maxi); mini = min(nums[i], mini);
            diff = maxi-mini;
            ans = max(ans, diff);
        }return ans*k; 
        
    }
};