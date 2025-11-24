class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0; 
        int i= 0;
        while(i<nums.size())
        {
            if(nums[i] == 0)
            {
                i++; continue;
            }
            int j = i; 
            while(i<nums.size()&&nums[i] == 1)
            {
                i++;
            }
            ans = max(ans, i-j);
        }return ans; 
        
    }
};