class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i = l; i<=r; i++)
        {
            int  c = 0;
            int sum = 0; 
            while(c < i)
                sum += nums[c++];
            int j = i; int f = 0;
            if(sum>0) 
                ans = min(ans, sum);
            while(j < nums.size())
            {
                sum -= nums[f++];
                sum += nums[j++];
                if(sum >0)
                    ans = min(ans, sum);
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans; 
    }
};