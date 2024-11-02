class Solution {
    int MOD  = 1000000007;
    long long fn(int idx, vector<vector<int>>&types, int target,
    vector<vector<int>>&dp)
    {
        if(target ==0)
            return 1;
        
        if(target<0)
            return 0;
        
        if(idx>=types.size())
            return 0;
        auto &ret = dp[idx][target];
        if(ret != -1)   
            return ret;
        
        
        
        
        long long ans = 0; 
        int cnt =0;
       
            
            int x = types[idx][0];
            while(x--)
            {
                cnt++;
                if(target-types[idx][1]*cnt<0)
                    break;
                long long temp =  fn(idx+1, types, target-types[idx][1]*cnt, dp);
                ans =  (ans+temp)%MOD;
            }
            cnt=0;
        long long temp2 = fn(idx+1, types, target, dp);
        ans = (ans+temp2)%MOD;
        return ret = (int)ans;

        
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {


        
        vector<vector<int>>dp(types.size()+1,vector<int>(target+1,-1));
        
        return (int)fn(0, types, target, dp);
        



        
    }
};