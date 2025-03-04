/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function(nums, pivot) {
    let ids=[] ;
        let ids2 =[] ;
        let ids3 =[] ;
        for(let i = 0; i< nums.length; i++)
        {
            if(nums[i] <pivot)
            {
                ids.push(i);
            }
            else if(nums[i] == pivot)
            {
                ids2.push(i);
            }
            else
            {
                ids3.push(i);
            }
        }
        let res = [];
        for(let i = 0; i< ids.length; i++)
        {
            res.push(nums[ids[i]]);
        }
        for(let i = 0; i< ids2.length; i++)
        {
            res.push(nums[ids2[i]]);
        }
        for(let i = 0; i< ids3.length; i++)
        {
            res.push(nums[ids3[i]]);
        }return res;
    
};