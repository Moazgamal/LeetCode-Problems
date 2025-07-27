class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int ans = 0; 
        for(int i = 1; i< nums.size()-1; i++)
        {
            int j = i-1; int k = i+1;
            while(k<nums.size() && nums[k] == nums[i])
            {
                k++;
            }
            if(k< nums.size())
            {
                if(nums[j]<nums[i] && nums[k]<nums[i])
                {
                    ans++; continue;
                }
                else if(nums[j] > nums[i] && nums[k]>nums[i])
                {
                    ans++; continue;
                }
            }
            i=k-1;
        }
        return ans;
        
    }
};