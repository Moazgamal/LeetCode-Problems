class Solution {
    int total = 0;
    unordered_map<long long, int> memo; // key = idx * 10000 + sum (to compress state)

    int fn(vector<int>& stones, int idx, int currSum) {
        if (idx == stones.size()) {
            int other = total - currSum;
            return abs(other - currSum);
        }

        long long key = ((long long)idx << 32) | currSum;
        if (memo.count(key)) return memo[key];

        // choose: add stone to subset1 or subset2
        int take = fn(stones, idx + 1, currSum + stones[idx]);
        int skip = fn(stones, idx + 1, currSum);
        return memo[key] = min(take, skip);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        total = accumulate(stones.begin(), stones.end(), 0);
        return fn(stones, 0, 0);
    }
};
