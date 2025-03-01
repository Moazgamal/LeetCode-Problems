class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i< nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = 2*nums[i];
                nums[i+1] = 0; 
            }
        }
        int j = -1;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                if(j !=-1)
                {
                    nums[j] = nums[i];
                    nums[i] = 0; 
                    j++;
                    while(j< nums.size() && nums[j] != 0)
                        j++;
                }
            }
            else if(j == -1)
                j= i;
        }return nums;
    }
};