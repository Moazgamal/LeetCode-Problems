class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = INT_MIN;

        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if(nums[sz-1] >0 && nums[sz-2] >0)
        {
            long long acc = (long long)nums[sz-1]*nums[sz-2]*(1e5);
            ans = max(ans, acc);
            if(nums[0]<0)
            {
                acc = nums[sz-1]*(-1*1e5)*(nums[0]);
                ans = max(ans, acc);
            }
        }
        else if(nums[sz-1]>0)
        {
            long long acc = nums[0]*nums[1]*(1e5);
            ans = max(ans, acc);
            acc = nums[0]*(-1*1e5)*nums[sz-1];
            ans  = max(ans, acc);
        }

        long long acc = (long long)nums[0]* nums[1] * (1e5);
        ans = max(ans, acc);
        acc = nums[0]*(-1*1e5)*nums[sz-1];
        ans = max(ans, acc);
        acc = (1e5)*nums[sz-1]*nums[sz-2];
        ans = max(ans, acc); 
        return ans;

        
    }
};