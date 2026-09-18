class Solution {
    int MOD = 1e9+7;
    int Dp[1001][1001];
    int fn(int IDX, int k, int n)
    {

        auto &ret = Dp[IDX][k];

        if(ret != -1)
            return Dp[IDX][k]; 
        if(k >0 && n-IDX-1 <k)
            return ret = 0; 
        if(IDX == n-1 && k>0)
            return  ret = 0; 
        if(IDX == n)
            return  Dp[IDX][k] = 0; 
        if(k == 0)
            return Dp[IDX][k] = 1; 
        
        int pick = 0; 
        for(int i = IDX+1; i<n; i++)
        {
            pick += fn(i, k-1, n);
            pick %= MOD;
        }
        int leave = fn(IDX+1, k, n);
        leave %= MOD;

        // cout<<pick<<" "<<IDX<<"\n";
        return  Dp[IDX][k] = (pick+leave)%MOD;
    }
public:
    int numberOfSets(int n, int k) {

        memset(Dp, -1, sizeof(Dp));
        return fn(0, k, n);
        // for(int i = 0; i< n; i++)
        // {
        //     cout<<Dp[i][k]<<" ll\n";
        // }

        return Dp[0][k];
    }
};