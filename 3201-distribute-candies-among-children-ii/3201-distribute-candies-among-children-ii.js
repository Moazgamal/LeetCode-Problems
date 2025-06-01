/**
 * @param {number} n
 * @param {number} limit
 * @return {number}
 */
var distributeCandies = function(n, limit) {

    let j = n - (2*limit);
       let x1 = 0; 
       let x2 = 0; 
       if(j <0)
       {
            x1 = 0; 
            x2 = Math.min(n, limit);
       }
       else
       {
            x1 = j;
            x2 = Math.min(n, limit);
       }
        let  ans = 0; 
       for(let k = x1 ; k<=x2 ; k++)
       {
            let cand = n;
            cand -= k;
            let x3 = 0; 
            let x4 = 0; 
            let u = cand- (limit);
            if(u < 0)
            {
                x3 = 0;
                x4 = Math.min(cand, limit);
            }
            else
            {
                x3 = u;
                x4 = Math.min(cand, limit);
            }
            let num = (x4-x3)+1;
            ans += num;
       }
       return ans; 
    
};