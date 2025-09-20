class Solution {
    int fn(int idx1, int idx2, vector<int>&nums1, vector<int>&nums2,
    vector<vector<int>>&dp)
    {
        if(idx1 >= nums1.size() || idx2 >= nums2.size())
            return INT_MIN/2; 
        auto &ret = dp[idx1][idx2];
        if(ret != INT_MIN/4)
            return ret; 
        int c1 = (nums1[idx1]*nums2[idx2]);
        int c2 = fn(idx1+1, idx2, nums1, nums2, dp);
        int c3 = fn(idx1+1, idx2+1, nums1, nums2, dp);
        int c4 = fn(idx1, idx2+1, nums1, nums2, dp);
        c1 = max(c1, c1+c3);
        return ret = max(c1, max(c2, c4));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1, INT_MIN/4));

        return fn(0, 0, nums1, nums2, dp);
        
    }
};