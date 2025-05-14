/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function(grid) {

    let rows ={};
        let cols = {};
        let tot = 0; 
        for(let r = 0; r< grid.length; r++)
            {
                let sum = 0; 
                for(let c = 0; c< grid[0].length; c++)
                    {
                        sum += grid[r][c];
                    }
                rows[r] = sum;
                tot += sum;
            }
        for(let c = 0; c< grid[0].length; c++)
            {
                let sum = 0; 
                for(let r = 0; r< grid.length; r++)
                    {
                        sum += grid[r][c];
                    }
                cols[c] = sum;
            }
       
         sum1 = 0; 
        for(let i = 0; i< grid.length-1; i++)
            {
                sum1 += rows[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        sum1 = 0; 
        for(let i = 0; i< grid[0].length-1; i++)
            {
                sum1 += cols[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        return false;
    
};