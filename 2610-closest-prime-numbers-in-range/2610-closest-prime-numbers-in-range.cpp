class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1);
        vector<bool> v(right+1,true);
        v[1] = false;
        int ans = -1; 
        int f = ceil(sqrt(right));
        int lastprime = -1; 
        for(int i = 2; i<= right; i++)
        {
            if(v[i] == true)
            {
                for(int j = i+i; j<= right; j+=i)
                {
                    v[j] = false;
                }
            }
        }
        for(int i = left ; i<= right; i++)
        {
            if(v[i] == true)
            {
                if(ans == -1)
                {
                    if(res[0] == -1)
                    {
                        res[0] = i;
                    }
                    else 
                    {
                        res[1]  = i;
                        ans = i-res[0];
                        lastprime = i; 
                    }
                }
                else
                {
                    if(i-lastprime < ans)
                    {
                        ans = i-lastprime;
                        res[1] = i;
                        res[0] = lastprime;
                    }
                    lastprime = i ;
                    
                }
            }
        }
        if(res[0]==-1 || res[1] == -1)
            return {-1,-1};
        return res;


    }
};