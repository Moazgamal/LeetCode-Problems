/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    function backtracking(idx ,st, ans,sz)
    {
        if(idx === sz)
        {
            if(!st.includes(ans.join("")))
            {
                return true;
            }
            return false;
        }
        ans.push('0');
        if(backtracking(idx+1, st, ans, sz))
            return true;
        ans.pop();
        ans.push('1');
        if(backtracking(idx+1, st,ans, sz))
            return true;
        ans.pop();
        return false;
    }
    let st = [];
        for(let i =0; i< nums.length; i++)
        {
            st.push(nums[i]);
        }
        let ans = [];
        let sz = nums.length;
        backtracking(0, st, ans, sz);
        return ans.join("");
};