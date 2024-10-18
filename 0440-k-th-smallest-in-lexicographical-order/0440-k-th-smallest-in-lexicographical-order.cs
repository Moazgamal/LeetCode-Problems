public class Solution {
    public int FindKthNumber(int n, int k) {
        long count_steps(long prefix1, long prefix2, long n)
    {
        long steps = 0;
        while(prefix1 <=n)
        {
            steps += (long.Min(prefix2, n+1) - prefix1);
            prefix1 *=10;
            prefix2 *=10;
        }return steps;
    }
    long curr = 1;
        k--;
        long n2 = (long)n;
        while(k>0)
        {
            long steps = count_steps(curr,curr+1,n2);
            if(steps>k)
            {
                curr*=10;
                --k;
            }
            else
            {
                k-= (int)steps;
                curr++;
            }
        }


        return (int)curr;

        
    }
}