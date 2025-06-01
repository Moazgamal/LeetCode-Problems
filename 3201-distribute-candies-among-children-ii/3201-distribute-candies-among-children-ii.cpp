class Solution {
    long long fn(int idx, int candies, int limit)
    {
        if(idx == 2)
        {
            return 1; 
        }
        long long cnt = 0; 
        for(int i = 0; i<= limit; i++)
        {
            int num= (3-idx)-1;
            if(num*limit < candies-i || candies-i<0)
                continue;
            // cout<<candies-i<<"fasdf\n";
            cnt += fn(idx+1, candies-i, limit);
        }
        return cnt ;
    }
public:
    long long distributeCandies(int n, int limit) {

       int j = n - (2*limit);
       int x1 = 0; 
       int x2 = 0; 
       if(j <0)
       {
            x1 = 0; 
            x2 = min(n, limit);
       }
       else
       {
            x1 = j;
            x2 = min(n, limit);
       }
        long long ans = 0; 
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
                x4 = min(cand, limit);
            }
            else
            {
                x3 = u;
                x4 = min(cand, limit);
            }
            int num = (x4-x3)+1;
            ans += num;
       }
       return ans; 
        
    }
};