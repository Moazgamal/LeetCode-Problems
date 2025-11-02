class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans = INT_MIN;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        long long acc = (long long)nums[0]*nums[1]*(1e5);
        ans = max(ans, acc);
        acc = nums[0]*(-1*1e5)*nums[sz-1];
        ans = max(ans, acc);
        acc = (long long)nums[sz-1]*nums[sz-2]*(1e5);
        ans = max(ans, acc);
        return ans;

        
    }
};