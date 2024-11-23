class Solution {
    const int MOD = 1000000007;
    int dp[801][2][801];
    int cnt[801];
    int solve(int idx, string &s, int &k , int tight, int setbits)
    {
        if(idx== s.size())
        {
            if(tight==1 || setbits==0)
                return 0;
            if(cnt[setbits] <=k)
                return 1;
            return 0;
        }
        
        
        if(s[idx]=='1')
            setbits++;
        auto &ret = dp[idx][tight][setbits];
        if(dp[idx][tight][setbits] != -1)
            return dp[idx][tight][setbits];
        if(cnt[setbits]>k+3)
            return ret =0;
        ret = 0;
        if(tight ==1)
        {
            if(s[idx]=='1')
                {
                    ret = (ret+ solve(idx+1, s, k, 0, setbits-1))%MOD;
                    ret = (ret+solve(idx+1, s, k, 1, setbits))%MOD;
                }
            else
                {
                    ret = (ret+solve(idx+1, s, k, 1, setbits))%MOD;
                }
        }
        else
        {
            if(s[idx]=='1')
                {
                    ret = (ret +solve(idx+1,s,k,0,setbits-1))%MOD;
                    ret = (ret+solve(idx+1, s, k, 0, setbits))%MOD;
                }
            else
            {
                ret = (ret+solve(idx+1, s, k, 0, setbits))%MOD;
                ret  = (ret +solve(idx+1, s, k, 0, setbits+1))%MOD;
            }
        }
        return dp[idx][tight][setbits] = ret;
    }
public:
    int countKReducibleNumbers(string s, int k) {
        
        cnt[1]=1
        ;
        for(int i = 2; i<=800; i++)
        {
            int setbits = __builtin_popcount(i);
            cnt[i]= 1+cnt[setbits];
        }
        memset(dp, -1, sizeof(dp));
        int tight = 1; 
        int setbits = 0;
        int ans = solve(0, s, k, tight, setbits);
        return ans;
        
        
        
    }
};