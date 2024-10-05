public class Solution {

    public int CalculateMinimumHP(int[][] dungeon) {


        
        int[,] dp = new int[dungeon.Length,dungeon[0].Length];
        return fn(0,0, ref dungeon, ref dp)<=0 ? 1:dp[0,0]+1;


     int fn(int r, int c , ref int[][]dun, ref int[,]dp)
    {
        if(r<0 || c<0 || r>= dun.Length || c>=dun[0].Length)
            return int.MaxValue/2;
        
        int ret = dp[r,c];
        if(ret != 0)
            return ret;
        if(r== dun.Length-1 && c == dun[0].Length-1)
        {
           if(dun[r][c]>=0)
                return dp[r,c] = 0;
            return dp[r,c] =  (-dun[r][c]);
        }
        
        int c1 =  fn(r+1,c, ref dun, ref dp);
        int c2 = fn(r,c+1,ref dun,ref dp);
            
       int minicost = -1*dun[r][c] + int.Min(c1,c2);
       if(minicost >0)
        return dp[r,c] = minicost;
        return dp[r,c] = 0;
        
    }
        
    }
}