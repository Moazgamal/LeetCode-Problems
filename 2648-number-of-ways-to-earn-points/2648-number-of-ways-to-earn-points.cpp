class Solution {
    int MOD  = 1000000007;
    long long fn(int idx, vector<vector<int>>&types, int target,
    vector<vector<int>>&dp)
    {
        if(target ==0)
            return 1;
        
        if(target<0)
            return 0;
        
        
        auto &ret = dp[idx][target];
        if(ret != -1)   
            return ret;
        
        
        
        
        long long ans = 0; 
        int cnt =0;
        for(int i = idx; i< types.size(); i++)
        {
            
            int x = types[i][0];
            while(x--)
            {
                cnt++;
                if(target-types[i][1]*cnt<0)
                    break;
                long long temp =  fn(i+1, types, target-types[i][1]*cnt, dp);
                ans =  (ans+temp)%MOD;
            }
            cnt=0;
        }
        return ret = (int)ans;

        
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {


        
        vector<vector<int>>dp(types.size()+1,vector<int>(target+1,-1));
        
        return (int)fn(0, types, target, dp);
        



        
    }
};