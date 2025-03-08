/**
 * @param {string} blocks
 * @param {number} k
 * @return {number}
 */
var minimumRecolors = function(blocks, k) {
     let indicies = [];
        let ans = Number.MAX_SAFE_INTEGER;
        for(let i = 0; i< blocks.length; i++)
        {
            if(blocks[i]=='B')
            {
                let j = i;
                while(j< blocks.length && blocks[j] == 'B')
                    j++;
                if(j-i >= k)
                    return 0; 
                indicies.push([i,j-1]);
                i=j;
            }
        }
        if(indicies.length == 0)
            return k;
        if(indicies.length == 1)
        {
            let value = indicies[0][1] - indicies[0][0] +1;
            k-=value;
            return k; 
        }
        for(let i = 0; i < indicies.length; i++)
        {
            let totalOperations = 0; 
            let start  = indicies[i][0];
            let end  = indicies[i][1];
            let rest = k; 
            rest -= (end-start+1);
            for(let j = i+1; j < indicies.length; j++)
            {
                let start2  = indicies[j][0];
                let end2  = indicies[j][1];
                let currentOperation = (start2 - end - 1);
                if(rest <=0)
                {
                    ans = Math.min(ans, totalOperations);
                    break;
                }
                if(rest - currentOperation ==0)
                {
                    ans = Math.min(ans, totalOperations+currentOperation);
                    break;
                }
                else if(rest - currentOperation <0)
                {
                    ans = Math.min(ans, totalOperations + rest);
                    break;
                }
                else
                {
                    rest -= currentOperation;
                    rest -= (end2-start2+1);
                    totalOperations += currentOperation;
                    if(rest<=0)
                        ans = Math.min(ans, totalOperations);
                }
                end = end2; 
                start = start2;
            }
            if(rest >0)
                ans = Math.min(ans, totalOperations+rest);
        }
        return ans;
    
};