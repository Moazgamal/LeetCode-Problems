class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0; 
        int i = 0; 
        while(i < (int)nums.size())
        {
            if(nums[i] != 0)
                i++;
            else
            {
                int factor = 1; 
                while(i < nums.size() && nums[i] == 0)
                {
                    ans += factor; factor++;
                    i++;
                }
            }
        }
        return ans; 
        
    }
};