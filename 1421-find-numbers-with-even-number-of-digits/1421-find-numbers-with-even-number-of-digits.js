/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let ans = 0; 
        for(let i = 0; i< nums.length; i++)
        {
            let cnt = 0;
           
            while(Math.floor(nums[i]) > 0)
            {
                nums[i] = nums[i]/ 10; 
                cnt++;
            }
            
            if(cnt %2 ==0)
                ans++;
        }return ans;
    
};