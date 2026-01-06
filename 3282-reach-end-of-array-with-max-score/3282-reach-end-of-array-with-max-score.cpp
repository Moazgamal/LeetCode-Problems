class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0; 
        int curVal = nums[0];
        for(int i = 1; i< nums.size(); i++)
        {
            ans += curVal;
            if(nums[i] > curVal)
                curVal = nums[i];
        }
        return ans; 
        
    }
};