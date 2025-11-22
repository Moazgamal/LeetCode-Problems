/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {

    let ans = 0; 
        for(let i = 0; i< nums.length; i++)
        {
            if(nums[i] % 3 == 0)
            {
                continue;
            }
            let x1 = Math.floor(nums[i] /3);
            let c1 = (nums[i]-(x1*3));
            let c2 = ((3*(x1+1))-nums[i]);
            ans += Math.min(c1, c2);
        }return ans; 
    
};