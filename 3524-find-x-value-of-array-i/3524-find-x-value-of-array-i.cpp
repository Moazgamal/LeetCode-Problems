using ll = long long;
class Solution {
    ll fn(int idx, int k , vector<vector<ll>> &dp, ll prevProduct, int x, vector<ll> &answer,
    vector<int>&nums)
    {
        if(idx==nums.size())
            return 0; 
        auto &ret = dp[idx][prevProduct+1];
        if(ret != -1)
            return ret;
        if(prevProduct == -1)
        {
            int cnt =0; 
            if(nums[idx] == x)
                cnt++;
            ll take = cnt + fn(idx+1, k, dp, nums[idx], x, answer,nums);
            ll leave = fn(idx+1, k, dp, prevProduct, x, answer,nums);
            return ret = take+leave;
        }
        int cnt = 0; 
        if((prevProduct*nums[idx])%k == x)
            cnt++;
        ll take = cnt + fn(idx+1, k, dp, (prevProduct*nums[idx])%k, x, answer,nums);
        
        return ret = take;
        
    }
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        for(int i = 0; i< nums.size(); i++)
        {
            nums[i] = nums[i]%k;
        }
       vector<ll> answer(k,0);

       for(int i = 0; i< k; i++)
       {
            vector<vector<ll>> dp(nums.size(), vector<ll>(k+1,-1));
            fn(0, k, dp, -1,i, answer,nums);
            answer[i] = dp[0][0];
       }
       return answer;
    }
};