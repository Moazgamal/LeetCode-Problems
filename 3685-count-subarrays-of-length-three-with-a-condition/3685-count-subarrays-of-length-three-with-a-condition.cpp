class Solution {
public:
    int countSubarrays(vector<int>& nums) {
int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            if(i+2<nums.size())
            {
                if(nums[i] + nums[i+2] == (double)nums[i+1]/2)
                    ans++;
            }
        }return ans;
        
    }
};