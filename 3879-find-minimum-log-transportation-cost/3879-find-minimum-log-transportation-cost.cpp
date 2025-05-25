class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k)
            return 0; 
        long long cost = LLONG_MAX; 
        
        if(n>k)
        {
            for(long long i = 1; i<=n/2; i++)
            {
                if(i<=k && n-i <=k)
                {
                    cost = min(cost, i*(n-i));
                }
            }
        }
        else
        {
            for(long long i = 1; i<=m/2; i++)
            {
                if(i<=k && m-i <=k)
                {
                    cost = min(cost, i*(m-i));
                }
            }
        }
        return cost;

        
    }
};