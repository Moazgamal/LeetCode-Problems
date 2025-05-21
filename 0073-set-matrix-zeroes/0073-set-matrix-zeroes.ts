/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {

    let FirstRow = false;
        let FirstCol = false;
        for(let c = 0; c< matrix[0].length; c++)
        {
            if(matrix[0][c] == 0)
            {
                FirstRow = true; break; 
            }
        }
    
        for(let r = 0; r< matrix.length; r++)
        {
            if(matrix[r][0] == 0)
            {
                FirstCol = true; break; 
            }
        }


        for(let j = 0; j< matrix.length; j++)
        {
            for(let k = 0; k< matrix[0].length; k++)
            {
                if(matrix[j][k] ==0)
                {
                    matrix[0][k] = 0; 
                    matrix[j][0] = 0; 
                }
            }
        }
        
        for(let m = 1; m< matrix[0].length; m++)
        {
            if(matrix[0][m] ==0)
            {
                for(let x = 1; x< matrix.length; x++)
                {
                    matrix[x][m] = 0; 
                }
            }
        }

        for(let l = 1; l< matrix.length; l++)
        {
            if(matrix[l][0] ==0)
            {
                for(let y = 1; y< matrix[0].length; y++)
                {
                    matrix[l][y] = 0; 
                }
            }
        }

        if(FirstRow == true)
        {
            for(let u = 0; u< matrix[0].length; u++)
                matrix[0][u] = 0; 
        }
        if(FirstCol == true)
        {
            for(let t = 0; t< matrix.length; t++)
                matrix[t][0]  = 0;
        }
    
};