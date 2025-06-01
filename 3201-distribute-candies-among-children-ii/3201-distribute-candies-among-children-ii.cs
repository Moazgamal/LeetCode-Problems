public class Solution {
    public long DistributeCandies(int n, int limit) {
        int j = n - (2*limit);
       int x1 = 0; 
       int x2 = 0; 
       if(j <0)
       {
            x1 = 0; 
            x2 = int.Min(n, limit);
       }
       else
       {
            x1 = j;
            x2 = int.Min(n, limit);
       }
        long  ans = 0; 
       for(int k = x1 ; k<=x2 ; k++)
       {
            int cand = n;
            cand -= k;
            int x3 = 0; 
            int x4 = 0; 
            int u = cand- (limit);
            if(u < 0)
            {
                x3 = 0;
                x4 = int.Min(cand, limit);
            }
            else
            {
                x3 = u;
                x4 = int.Min(cand, limit);
            }
            int num = (x4-x3)+1;
            ans += num;
       }
       return ans; 
    }
}