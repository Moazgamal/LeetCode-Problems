class Solution {
    struct VecHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                h ^= std::hash<int>()(x) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
            }
            return h;
        }
    };

    // same helper you had
    vector<int> combine(int start, int end, const vector<int>& h, const vector<int>& v) {
        vector<int> ans;
        int i = start;
        if (start <= end) {
            for (; i <= end; ++i) ans.push_back(h[i]);
        }
        for (int x : v) ans.push_back(x);
        for (; i < (int)h.size(); ++i) ans.push_back(h[i]);
        return ans;
    }

    // depth-limited DFS (path-level visiting to avoid cycles)
    bool dfs_limited(const vector<int>& cur, const vector<int>& target, int rem,
                     unordered_set<vector<int>, VecHash>& visiting) {
        if (cur == target) return true;
        if (rem == 0) return false;

        visiting.insert(cur);
        int n = cur.size();

        for (int i = 0; i < n; ++i) {
            vector<int> v;              // removed subarray cur[i..j]
            for (int j = i; j < n; ++j) {
                v.push_back(cur[j]);
                vector<int> h;         // remaining elements
                for (int m = 0; m < n; ++m) {
                    if (m >= i && m <= j) continue;
                    h.push_back(cur[m]);
                }
                for (int k = 0; k <= (int)h.size(); ++k) {
                    vector<int> u = combine(0, k - 1, h, v);
                    if (u == cur) continue;                  // skip no-op
                    if (visiting.find(u) != visiting.end()) continue; // avoid cycle on this path
                    if (dfs_limited(u, target, rem - 1, visiting)) {
                        visiting.erase(cur);
                        return true;
                    }
                }
            }
        }

        visiting.erase(cur);
        return false;
    }

public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        int n = nums1.size();

        unordered_set<vector<int>, VecHash> visiting;
        // try increasing depth limits; n is safe upper bound for this problem
        for (int depth = 1; depth <= n; ++depth) {
            visiting.clear();
            if (dfs_limited(nums1, nums2, depth, visiting)) return depth;
        }
        return -1; // per constraints shouldn't happen
    }
};
