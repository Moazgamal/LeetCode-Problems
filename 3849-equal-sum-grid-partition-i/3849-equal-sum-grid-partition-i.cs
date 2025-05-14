public class Solution {
    public bool CanPartitionGrid(int[][] grid) {

        List<long> rows = new List<long>(new long[grid.Length]);
        List<long> cols = new List<long>(new long[grid[0].Length]);
        long tot = 0; 
        for(int r = 0; r< grid.Length; r++)
            {
                long sum = 0; 
                for(int c = 0; c< grid[0].Length; c++)
                    {
                        sum += grid[r][c];
                    }
                rows[r] = sum;
                tot += sum;
            }
        for(int c = 0; c< grid[0].Length; c++)
            {
                long sum = 0; 
                for(int r = 0; r< grid.Length; r++)
                    {
                        sum += grid[r][c];
                    }
                cols[c] = sum;
            }
       
        long sum1 = 0; 
        for(int i = 0; i< grid.Length-1; i++)
            {
                sum1 += rows[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        sum1 = 0; 
        for(int i = 0; i< grid[0].Length-1; i++)
            {
                sum1 += cols[i];
                if(tot-sum1 == sum1)
                    return true;
            }
        return false;
        
        
    }
}