class Solution {
    const int MOD= 1e9+7;
    int fn(int idx, vector<int>&arr, int target, vector<vector<vector<int>>>&dp, int rest)
    {
        if(target <0 || rest < 0)
            return 0;
       
        if(target == 0 && rest < 0)
            return 0 ;
        if(target == 0 && rest == 0)
            return 1; 
        auto &ret = dp[idx][target][rest];
        if(ret != -1)
            return ret;
        if(idx >= arr.size())
            return 0; 
        int c1 = fn(idx+1, arr, target-arr[idx], dp, rest-1)%MOD;
        int c2 = fn(idx+1, arr, target, dp, rest)%MOD;
        return ret = (c1+c2)%MOD;
    }
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<vector<vector<int>>>dp(arr.size()+1, vector<vector<int>>(target+1, vector<int>(4, -1)));
        return fn(0, arr, target, dp, 3);
        
    }
};