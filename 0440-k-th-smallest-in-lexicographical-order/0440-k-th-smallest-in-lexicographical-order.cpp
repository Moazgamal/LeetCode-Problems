class Solution {
    int count_steps(long long prefix1, long long prefix2, long long n)
    {
        int steps = 0;
        while(prefix1 <=n)
        {
            steps += (min(prefix2, n+1) - prefix1);
            prefix1 *=10;
            prefix2 *=10;
        }return steps;
    }
public:
    int findKthNumber(int n, int k) {


        
        long long curr = 1;
        k--;
        long long n2 = n;
        while(k>0)
        {
            long long steps = count_steps(curr,curr+1,n2);
            if(steps>k)
            {
                curr*=10;
                --k;
            }
            else
            {
                k-=steps;
                curr++;
            }
        }


        return curr;


        
        
    }
};