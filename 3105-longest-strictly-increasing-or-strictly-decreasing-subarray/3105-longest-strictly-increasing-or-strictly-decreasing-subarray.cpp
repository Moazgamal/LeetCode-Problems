class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            int cnt = 1; 
            while(i+1< nums.size() && nums[i] < nums[i+1])
            {
                cnt++; i++;
            }
            ans= max(ans, cnt);
        }
        for(int i = 0; i< nums.size(); i++)
        {
            int cnt =1; 
            while(i+1 < nums.size() && nums[i]> nums[i+1])
            {
                cnt++; i++;
            }
            ans = max(ans, cnt); 
        }return ans;
        
    }
};