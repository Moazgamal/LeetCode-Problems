/**
 * @param {number} n
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minCuttingCost = function(n, m, k) {

    if(n<=k && m<=k)
            return 0; 
         let cost = Number.MAX_SAFE_INTEGER;
        
        if(n>k)
        {
            for( let i = 1; i<=n/2; i++)
            {
                if(i<=k && n-i <=k)
                {
                    cost = Math.min(cost, i*(n-i));
                }
            }
        }
        else
        {
            for( let i = 1; i<=m/2; i++)
            {
                if(i<=k && m-i <=k)
                {
                    cost = Math.min(cost, i*(m-i));
                }
            }
        }
        return cost;
    
};