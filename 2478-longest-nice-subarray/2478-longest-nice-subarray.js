/**
 * @param {number[]} nums
 * @return {number}
 */
var longestNiceSubarray = function(nums) {
    let acc = nums[0] ; 
        let ans = 1; 
        let j = 0; 

        for(let i =1; i< nums.length; i++)
        {
            while((acc & nums[i])!=0 )
            {
                acc = acc ^ nums[j];
                j++;
            }
            acc = acc | nums[i];
            ans = Math.max(ans, i-j+1);
        }return ans;
    
};