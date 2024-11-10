class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        for(int i = 0; i< nums.size(); i++)
        {
            int j = i+1;
            for(; j<i+k && j< nums.size(); j++)
            {
                if(nums[j] > nums[j-1])
                    continue;
                else
                    break;
            }
            if(j<i+k)
                continue;
            int m = j+1;
            for(; m< j+k && m< nums.size(); m++)
            {
                if(nums[m]>nums[m-1])
                    continue;
                else
                    break;
            }
            if(m<j+k)
                continue;
            else
                return true;
            
        }return false;
    }
};