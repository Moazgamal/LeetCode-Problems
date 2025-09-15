class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        vector<int>ans; 
        for(int i  = 0; i< nums.size() && k>0; i++)
        {   
            if(i==0)
            {
                ans.push_back(nums[i]); k--; continue;
            }
            if(nums[i] == nums[i-1])
                continue;
            ans.push_back(nums[i]); k--;
        }
        return ans; 
        
    }
};