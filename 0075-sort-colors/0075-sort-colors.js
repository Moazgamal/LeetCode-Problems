/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {

    let cnt1 = 0; let cnt2 = 0; let cnt3= 0; 
        for(let i = 0; i< nums.length; i++)
        {
            if(nums[i] == 0)
                cnt1++;
            else if(nums[i] == 1)
                cnt2++;
            else
                cnt3++;
        }let j = 0; 
       
            while(cnt1-- >0)
                nums[j++]= 0;
            while(cnt2-- >0)
                nums[j++] = 1; 
            while(cnt3-->0)
                nums[j++] = 2;
    
};