/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    let mp = new Map();
        let ans = -1;
        
        for(let i = 0; i<= nums.length-k; i++)
            {
                let _k = k;
                let j = i;
                while(_k-- > 0)
                    {
                        let s = mp.get(nums[j]) ||0;
                        
                        mp.set(nums[j],s+1);
                        j++;
                    }
            }
        for(let [key,value] of mp){
                if(value == 1)
                {
                    ans = Math.max(ans, key);
                }
            };
        if(k == nums.length)
        {
            let res = -1;
            for(let i = 0; i< nums.length; i++)
                {
                    res = Math.max(res, nums[i]);
                }
            return res;
        }
        return ans;
    
};