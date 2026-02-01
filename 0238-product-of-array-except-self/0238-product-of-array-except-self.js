/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let result = [];
        for(let i = 0; i< nums.length; i++)
            result.push(1);
        let acc = 1; 
        for(let i = 0; i< nums.length-1; i++)
        {
            result[i+1] = acc*nums[i];
            acc*=nums[i];
        }
        acc =1 ; 
        for(let i = nums.length-1; i >= 1; i--)
        {
            result[i-1] *= (acc*nums[i]);
            acc*=nums[i];
        }
        return result;
    
};