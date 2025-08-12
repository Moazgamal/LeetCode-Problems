class Solution {
    const int MOD = 1e9+7;
    long long dp[5001][7][16];
    long long fn(int i , int last , int cnt, int &n, vector<int>&rollMax)
    {
        if(i==n)return 1;

        if(dp[i][last][cnt]!=-1) return dp[i][last][cnt];
       
        if(i == n)
        {
            return 1; 
        }
        long long  ans = 0; 
        for(int j = 1; j<=6; j++)
        {
            if(j== last)
            {
                if(cnt+1 <= rollMax[j-1])
                    ans+= fn(i+1, last, cnt+1,n, rollMax);
                ans %= MOD;
            }
            else
            {
                ans+=fn(i+1,j,1,n, rollMax);
                ans %= MOD;
            }
        }
        return dp[i][last][cnt] = ans;

    }

public:
    int dieSimulator(int n, vector<int>& rollMax) {

        memset(dp,-1,sizeof(dp));
        return fn(0,0,0,n, rollMax);
        
    }
};