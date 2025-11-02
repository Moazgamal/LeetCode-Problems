class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = INT_MIN;
        int sz = nums.size();
        long long firstPos = INT_MIN;
        long long secondPos = INT_MIN;
        long long firstNeg = INT_MAX;
        long long secondNeg = INT_MAX;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i]<0)
            {
                if(nums[i]< firstNeg)
                {
                    secondNeg = firstNeg;
                    firstNeg = nums[i];
                }
                else if(nums[i]<secondNeg)
                {
                    secondNeg = nums[i];
                }
            }
            else if(nums[i] > 0)
            {
                if(nums[i] > firstPos)
                {
                    secondPos = firstPos;
                    firstPos = nums[i];
                }
                else if(nums[i] > secondPos)
                {
                    secondPos = nums[i];
                }
            }
        }
        long long Constant = 1e5;
        if(firstNeg != INT_MAX && secondNeg != INT_MAX)
        {
            ans = max(ans, firstNeg*secondNeg*(Constant));
            if(firstPos != INT_MIN)
                ans = max(ans, firstNeg*(-1*Constant)*firstPos);
        }
        else if(firstNeg != INT_MAX)
            ans = max(ans, firstNeg*(-1*Constant)*firstPos);
            
        if(firstPos != INT_MIN && secondPos != INT_MIN)
            ans = max(ans, firstPos*secondPos*(Constant));
        else
            ans = max(ans, (long long)0);
        return ans;

        
    }
};