class Solution {
    void fn(int idx, vector<int>&nums, int &ans, int acc)
    {
        if(idx>=nums.size())
        {
            
            ans += acc;return ; 
        }
        fn(idx+1, nums, ans, acc^nums[idx]);
        fn(idx+1, nums, ans, acc);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0; int acc = 0; 
        fn(0, nums, ans, acc);
       return ans;
    }
};