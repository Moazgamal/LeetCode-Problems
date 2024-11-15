using ll = long long;
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {

        int MAX = 100001;
        int MOD = 1000000007;
        vector<ll> dp(MAX,0);
        vector<ll> sums(MAX,0);
        ll result = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            bool x = false;
            ll x2 = sums[nums[i]];
            
            dp[nums[i]] = (dp[nums[i]]+1)%MOD;
            sums[nums[i]] =(sums[nums[i]] + nums[i])%MOD;
            if(nums[i]-1>=0 && dp[nums[i]-1]>0)
            {
                dp[nums[i]] = (dp[nums[i]] + dp[nums[i]-1])%MOD;
                sums[nums[i]] = (sums[nums[i]] + sums[nums[i]-1] + (nums[i]*dp[nums[i]-1])%MOD)%MOD;
            }
            if(nums[i]+1<MAX && dp[nums[i]+1]>0)
            {
                dp[nums[i]] = (dp[nums[i]] + dp[nums[i]+1])%MOD;
                sums[nums[i]] = (sums[nums[i]] + sums[nums[i]+1] + (nums[i]*dp[nums[i]+1])%MOD)%MOD;
            }
           
                
        }
        for(int i = 0; i< MAX; i++)
        {
            result  = (result+ sums[i])%MOD;
        }
        return (int)result;
    }
};