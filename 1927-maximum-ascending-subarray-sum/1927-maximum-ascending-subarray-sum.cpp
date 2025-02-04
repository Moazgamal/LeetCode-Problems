class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            int sum = nums[i];
            while(i+1< nums.size() && nums[i]<nums[i+1])
            {
                sum += nums[i+1];
                i++;
            }
            ans = max(ans, sum);
        }return ans;
        
    }
};