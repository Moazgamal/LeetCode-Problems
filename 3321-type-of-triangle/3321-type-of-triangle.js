/**
 * @param {number[]} nums
 * @return {string}
 */
var triangleType = function(nums) {

    let n1 = nums[0];
        let n2 = nums[1];
        let n3 = nums[2];
        if(n1 + n2 <= n3 || n1+n3 <= n2 || n2+n3<=n1)
            return "none";
        if(n1 == n2  && n2== n3)
            return "equilateral";
        if(n1 == n2 || n1 == n3 || n2 == n3)
            return "isosceles";
        return "scalene";
        
    
};