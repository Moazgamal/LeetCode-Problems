class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 2; 
        int i = 0; 
        while(i< nums.size()-2)
        {
            int j = i+1; int k = i+2;
            int orgI = i; 
            while(k<nums.size())
            {
                if(nums[i]+nums[j]== nums[k])
                {
                    ans = max(ans, k-orgI+1);
                    i++;j++;
                    k++;
                }
                else
                {
                    i= j; break;
                }
            }
            if(k == nums.size())
                break; 
        }return ans; 
        
    }
};