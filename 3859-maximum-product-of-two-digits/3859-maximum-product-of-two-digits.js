/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
     let ans = 0; 
        let s = n.toString();
        for(let i = 0; i< s.length; i++)
            {
                for(let j = i+1; j< s.length; j++)
                    {
                        ans = Math.max(ans, (s[i]-'0')*(s[j]-'0'));
                    }
            }
        return ans;
    
};