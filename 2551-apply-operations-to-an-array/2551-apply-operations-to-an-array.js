/**
 * @param {number[]} nums
 * @return {number[]}
 */
var applyOperations = function(nums) {
    for(let i = 0; i< nums.length-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = 2*nums[i];
                nums[i+1] = 0; 
            }
        }
        let j = -1;
        for(let i = 0; i< nums.length; i++)
        {
            if(nums[i] != 0)
            {
                if(j !=-1)
                {
                    nums[j] = nums[i];
                    nums[i] = 0; 
                    j++;
                    while(j< nums.length && nums[j] != 0)
                        j++;
                }
            }
            else if(j == -1)
                j= i;
        }
        return nums;
    
};