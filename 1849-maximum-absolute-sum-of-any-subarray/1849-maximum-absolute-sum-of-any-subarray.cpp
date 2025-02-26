class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int PrefixSum = 0 ;
        int ans = 0; 
        int maxPos = 0;
        int maxNeg = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            PrefixSum += nums[i];
            ans = max(ans, abs(PrefixSum));
            if(PrefixSum >= 0)
            {
                if(maxNeg !=0)
                    ans = max(ans, PrefixSum-maxNeg);
            }
            else
            {
                if(maxPos != 0)
                    ans = max(ans, abs(PrefixSum-maxPos));
            }
            if(PrefixSum > 0)
            {
                if(maxPos != 0)
                {
                    if(maxPos < PrefixSum)
                        maxPos = PrefixSum;
                }
                else
                    maxPos = PrefixSum;
            }
            else
            {
                if(maxNeg != 0)
                {
                    if(maxNeg > PrefixSum)
                        maxNeg = PrefixSum;
                }
                else
                    maxNeg = PrefixSum;
            }
            
        }
        return ans;
        
    }
};