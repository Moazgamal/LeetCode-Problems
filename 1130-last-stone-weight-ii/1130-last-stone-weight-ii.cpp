class Solution {
    int total = 0;
    vector<vector<int>> dp; // memo table

    int fn(vector<int>& stones, int i, int currSum) {
        if (i == stones.size()) {
            int other = total - currSum;
            return abs(currSum - other); // الفرق النهائي
        }

        if (dp[i][currSum] != -1) return dp[i][currSum];

        // نحط الحجر في المجموعة الأولى
        int take = fn(stones, i + 1, currSum + stones[i]);
        // أو نحطه في المجموعة التانية (يعني مش نضيفه)
        int skip = fn(stones, i + 1, currSum);

        return dp[i][currSum] = min(take, skip);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        total = accumulate(stones.begin(), stones.end(), 0);
        dp.assign(stones.size() + 1, vector<int>(total + 1, -1));
        return fn(stones, 0, 0);
    }
};
