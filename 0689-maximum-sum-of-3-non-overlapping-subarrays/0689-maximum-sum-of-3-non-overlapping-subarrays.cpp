class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        //Calculate prefix sums
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        //Calculate prefix maximum subarray sums
        vector<int> leftMaxIdx(n, 0);
        int maxLeftSum = prefixSum[k] - prefixSum[0];
        for (int i = k; i < n; i++) {
            int currentSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currentSum > maxLeftSum) {
                maxLeftSum = currentSum;
                leftMaxIdx[i] = i - k + 1;
            } else {
                leftMaxIdx[i] = leftMaxIdx[i - 1];
            }
        }

        //Calculate suffix maximum subarray sums
        vector<int> rightMaxIdx(n, 0);
        int maxRightSum = prefixSum[n] - prefixSum[n - k];
        rightMaxIdx[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            int currentSum = prefixSum[i + k] - prefixSum[i];
            if (currentSum >= maxRightSum) {
                maxRightSum = currentSum;
                rightMaxIdx[i] = i;
            } else {
                rightMaxIdx[i] = rightMaxIdx[i + 1];
            }
        }

        //Iterate through all possible middle subarray starting indices
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int left = leftMaxIdx[i - 1];
            int right = rightMaxIdx[i + k];
            int currentSum = (prefixSum[left + k] - prefixSum[left]) +
                             (prefixSum[i + k] - prefixSum[i]) +
                             (prefixSum[right + k] - prefixSum[right]);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = {left, i, right};
            }
        }

        return result;
    }
};