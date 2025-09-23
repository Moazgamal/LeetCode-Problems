class Solution {
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

public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;
        int n = nums1.size();

        map<vector<int>, int> dist;  // بدل unordered_map + hash
        queue<vector<int>> q;

        dist[nums1] = 0;
        q.push(nums1);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int d = dist[cur];

            for (int i = 0; i < n; ++i) {
                vector<int> v; 
                for (int j = i; j < n; ++j) {
                    v.push_back(cur[j]);
                    vector<int> h;
                    for (int m = 0; m < n; ++m) {
                        if (m >= i && m <= j) continue;
                        h.push_back(cur[m]);
                    }
                    for (int k = 0; k <= (int)h.size(); ++k) {
                        vector<int> nxt = combine(0, k - 1, h, v);
                        if (nxt == cur) continue;
                        if (!dist.count(nxt)) {
                            dist[nxt] = d + 1;
                            if (nxt == nums2) return d + 1;
                            q.push(nxt);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
