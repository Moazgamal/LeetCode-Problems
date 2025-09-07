class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool x = true;
        int i = 1; 
        while(i < nums.size())
        {
            if(nums[i] == nums[i-1])
            {
                i++; 
            }
            else
            {
                x = false; break;
            }
        }
        if(x)
            return 0; 
        return 1; 
        
    }
};