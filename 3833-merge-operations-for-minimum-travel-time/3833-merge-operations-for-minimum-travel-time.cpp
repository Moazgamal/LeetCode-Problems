class Solution {
    
    int fn(int idx, vector<int> &pos, vector<int> &time, int l, int k, vector<int> &p,
    vector<vector<vector<int>>> &dp, int cur)
    {
        if(idx == time.size()-1)
        {
            if(k>0)
                return INT_MAX/2;
            return 0; 
        }
        auto &ret  = dp[idx][k][cur];
        if(ret != INT_MAX/2)
            return ret; 
        if(idx!=0)
            {
                
                ret = cur*(pos[idx+1]-pos[idx])+fn(idx+1, pos, time, l, k, p, dp, time[idx+1]);
            }
        else
            ret = cur*(pos[idx+1]-pos[idx])+fn(idx+1, pos, time, l, k, p, dp, time[idx+1]);
        for(int j = 1; k-- >0 ; j++)
        {
            if(idx+j+1>time.size()-1)
                break;
            int x = cur*(pos[idx+j+1]-pos[idx])+fn(idx+j+1, pos, time, l, k, p, dp, time[idx+j+1]+
            p[idx+j+1]-p[idx]-time[idx]);
            ret = min(ret,x );
        }
        return ret; 
        
    }
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<vector<vector<int>>> dp (time.size()+1, vector<vector<int>>(k+2, vector<int>(101,INT_MAX/2)));
        vector<int> prefixs(time.size(),0);
        int prefix = 0; 
        for(int i = 0; i< prefixs.size(); i++)
        {
            prefixs[i] = prefix;
            prefix += time[i];
        }
        return fn(0,position, time, l, k, prefixs,dp, time[0]);

        
    }
};