class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size(),1);
        int acc = 1; 
        for(int i = 0; i< nums.size()-1; i++)
        {
            result[i+1] = acc*nums[i];
            acc*=nums[i];
        }
        acc =1 ; 
        for(int i = nums.size()-1; i >= 1; i--)
        {
            result[i-1] *= (acc*nums[i]);
            acc*=nums[i];
        }
        return result;
    }
};