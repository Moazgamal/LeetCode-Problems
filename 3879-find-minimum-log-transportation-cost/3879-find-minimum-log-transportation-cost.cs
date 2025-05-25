public class Solution {
    public long MinCuttingCost(int n, int m, int k) {

        if(n<=k && m<=k)
            return 0; 
         long cost = long.MaxValue; 
        
        if(n>k)
        {
            for( long i = 1; i<=n/2; i++)
            {
                if(i<=k && n-i <=k)
                {
                    cost = long.Min(cost, i*(n-i));
                }
            }
        }
        else
        {
            for( long i = 1; i<=m/2; i++)
            {
                if(i<=k && m-i <=k)
                {
                    cost = long.Min(cost, i*(m-i));
                }
            }
        }
        return cost;
        
    }
}