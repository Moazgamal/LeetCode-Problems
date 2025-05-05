public class Solution {
    public int[][] SpecialGrid(int n) {
int N = n;
         if(N ==0)
            return new int[1][]{new int[1]{0}};
        int sz = 1<<N;
        int[,] array = new int[3, 4];
       int[][] ans = new int[sz][];
       for(int i = 0; i< ans.Length; i++)
       {
            ans[i] = new int[sz];
       }
         int cnt = 0; 
        build(0, sz-1, sz, ref cnt, ref ans);
        return ans;





        void build(int r, int cmax, int N, ref int cnt,  ref int[][] ans)
    {
        if(N == 2)
        {
            ans[r][cmax] = cnt++;
            ans[r+1][cmax] = cnt++;
            ans[r+1][cmax-1] = cnt++;
            ans[r][cmax-1] = cnt++;
            return ;
        }
        int x = N/2;
        for(int i = 0; i< 4; i++)
        {
            build(r, cmax, x, ref cnt, ref ans);
            if(i== 0)
                r+= x;
            if(i==1)
                cmax -= x;
            if(i==2)
                r -= x;
        }
    }
        
    }
}