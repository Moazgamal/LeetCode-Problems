class Solution {
    int  fn(int idx, vector<int>&arr, int &d, vector<int>&dp)
    {
        auto &ret = dp[idx];
        if(ret != -1)
            return ret; 
        int start = max(0,  idx-d);
        int end = min((int)arr.size()-1, idx+d);
        int maxsofar = -1; 
        ret = 0; 
        for(int i = idx-1; i>=start; i--)
        {
            if(arr[idx]<= arr[i])
                break;
            if(arr[idx]>arr[i] && arr[i]>=maxsofar)
            {
                maxsofar = arr[i];
                ret = max(ret, 1+fn(i, arr, d, dp));
            }
        }
        maxsofar = -1;
        for(int i = idx+1; i<=end; i++)
        {
            if(arr[idx]<= arr[i])
                break;
            if(arr[idx]>arr[i]  && arr[i]>=maxsofar)
            {
                maxsofar = arr[i];
                ret = max(ret, 1+fn(i, arr, d, dp));
            }
        }
        return ret; 
    }
public:
    int maxJumps(vector<int>& arr, int d) {

        int ans = 0; 
        vector<int>dp(arr.size(), -1);
        for(int i = 0; i< arr.size(); i++)
            ans = max(ans, 1+fn(i, arr, d, dp));
        return ans; 
        
    }
};