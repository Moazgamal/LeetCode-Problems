class Solution {
    int fn(int idx, vector<vector<int>>& q, int target, vector<vector<int>> &dp, int j)
    {
        if(target == 0)
            return j; 
        if(target < 0)
            return  q.size()+1;
        if(j >= q.size())
            return  q.size()+1; 
        auto &ret  = dp[target][j];
        if(ret != -1)
            return ret; 
       ret = fn(idx, q, target, dp, j+1); 
       if(q[j][0] <= idx && q[j][1] >= idx)
             ret = min(ret, fn(idx, q, target-q[j][2], dp,j+1));
        return ret; 
        
        
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;

       for(int i = 0; i< nums.size(); i++)
       {
            vector<vector<int>> dp(nums[i]+1, vector<int>(queries.size()+1, -1));
            ans = max(ans, fn(i, queries, nums[i], dp, 0));
       }
       if(ans == queries.size()+1)
            return -1;
        return ans; 


        
    }
};