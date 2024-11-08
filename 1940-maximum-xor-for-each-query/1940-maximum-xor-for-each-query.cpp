class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = pow(2, maximumBit)-1;
        vector<int>result(nums.size());
        for(int i=0; i< nums.size(); i++)
        {
            if(i==0)
                result[i] = nums[i]^x;
            else
            {
                result[i] = nums[i-1]^nums[i]^x;
                nums[i] = nums[i-1]^nums[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};