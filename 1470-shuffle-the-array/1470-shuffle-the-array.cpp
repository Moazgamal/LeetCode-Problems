class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int sz = nums.size()/2;
        int i = 0; int j = sz; vector<int>ans;
        while(j<nums.size())
        {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }return ans; 
        
    }
};