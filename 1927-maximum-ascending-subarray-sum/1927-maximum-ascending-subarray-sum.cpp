class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int i = 0;  
        while(i< nums.size())
        {
            int sum = nums[i];
            while(i+1< nums.size() && nums[i]<nums[i+1])
            {
                sum += nums[i+1];
                i++;
            }
            i++;
            ans = max(ans, sum);
        }return ans;
        
    }
};