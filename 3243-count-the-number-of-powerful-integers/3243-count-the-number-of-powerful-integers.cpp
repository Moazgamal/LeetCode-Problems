class Solution {
    long long dp[17][2];
    long long solve( string& end,int tight, int limit,string &s, int n)
    {
        if(end.size()< s.size())
            return 0;
        
        if(n<0)
            return 1ll;
        auto &ret = dp[n][tight];
        if(ret != -1)
            return ret;
        ret=0;
        

        if(n<=s.size())
        {
            if(tight == 1)
            {
                int ub= end[end.size()-n]-'0';
                int val = s[s.size()-n]-'0';
                if(ub<val)
                    return  ret =0;
                else if(ub ==val)
                    ret += solve( end, tight, limit, s, n-1);
                else
                {
                    return  ret =1;
                }
                
            }
            else
            {
                return  ret =1;
            }
        }
        else
        {
            int ub= end[end.size()-n]-'0';
            if(tight ==1)
            {
                for(int i = 0; i<=min(ub,limit); i++)
                {
                    ret += solve(end, (tight&(i==ub)), limit,s,n-1);
                }
            }
            else
            {
                for(int i = 0; i<=limit; i++)
                {
                    ret += solve(end, 0, limit,s,n-1);
                }
            }
                
           
        }
        return ret;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {


        memset(dp,-1,sizeof(dp));
        int tight = 1;
        string st = to_string(start-1);
        string f = to_string(finish);
        long long val1 = solve( f,tight, limit,s, f.size());
        memset(dp,-1,sizeof(dp));
        long long val2 = solve( st,tight, limit,s, st.size());
        cout<<val1<<" "<<val2<<"\n";
        long long ans = val1 -val2;
        return ans;
    }
};