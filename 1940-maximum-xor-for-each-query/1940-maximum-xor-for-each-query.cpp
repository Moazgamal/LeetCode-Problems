class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = (1<<maximumBit)-1;
        vector<int>result(nums.size());
        result[0] = nums[0]^x;
        for(int i=1; i< nums.size(); i++)
        {
            nums[i] = nums[i-1]^nums[i];
            result[i] = nums[i]^x;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};