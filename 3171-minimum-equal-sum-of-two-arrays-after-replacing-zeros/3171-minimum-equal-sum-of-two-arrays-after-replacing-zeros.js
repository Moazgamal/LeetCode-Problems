/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minSum = function(nums1, nums2) {

    let  ans = 0; 
        let  mini1 = 0; 
        let  maxi1 = mini1;
        let  mini2 = 0; 
        let  maxi2 = mini2;
        for(let i = 0; i< nums1.length; i++)
        {
            if(nums1[i] == 0)
            {
                mini1 += 1;
                maxi1 = Number.MAX_SAFE_INTEGER;
            }
            else
                mini1 += nums1[i];
        }
        for(let i = 0; i< nums2.length; i++)
        {
            if(nums2[i] == 0)
            {
                mini2 += 1;
                maxi2 = Number.MAX_SAFE_INTEGER;
            }
            else
                mini2 += nums2[i];
        }
        if(maxi1 != Number.MAX_SAFE_INTEGER)
            maxi1 = mini1;
        if(maxi2 != Number.MAX_SAFE_INTEGER)
            maxi2 = mini2;
        if(mini1 > maxi2 || mini2 > maxi1)
            return -1;
        return Math.max(mini1, mini2);

    
};