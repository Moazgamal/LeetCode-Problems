class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // change in indicies
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[abs(nums[i])-1] < 0)
                return abs(nums[i]);
            nums[abs(nums[i])-1] *= -1;
        }return 0; 
        
    }
};