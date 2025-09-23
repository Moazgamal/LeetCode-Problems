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

    vector<int> combine(int start, int end, vector<int>&h, vector<int>&v)
    {
        vector<int> ans;
        int i = start;
        if(start <= end) {
            for(; i <= end; i++) ans.push_back(h[i]);
        }
        for(int j = 0; j < v.size(); j++) ans.push_back(v[j]);
        for(; i < h.size(); i++) ans.push_back(h[i]);
        return ans;
    }

public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1 == nums2) return 0;

        unordered_map<vector<int>, int, VecHash> dist;
        queue<vector<int>> q;

        dist[nums1] = 0;
        q.push(nums1);

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int d = dist[cur];

            // generate neighbors
            for(int i = 0; i < cur.size(); i++) {
                vector<int> v;
                for(int j = i; j < cur.size(); j++) {
                    v.push_back(cur[j]);
                    vector<int> h;
                    for(int m = 0; m < cur.size(); m++) {
                        if(m >= i && m <= j) continue;
                        h.push_back(cur[m]);
                    }
                    for(int k = 0; k <= h.size(); k++) {
                        vector<int> u = combine(0, k-1, h, v);
                        if(u == cur) continue; // skip no-op
                        if(!dist.count(u)) {
                            dist[u] = d+1;
                            if(u == nums2) return d+1;
                            q.push(u);
                        }
                    }
                }
            }
        }

        return -1; // should never happen
    }
};
