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

        map<vector<int>, bool> vis;  
        queue<vector<int>> q;
        
        q.push(nums1);
        int level = 0; 
        while (!q.empty()) 
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front(); q.pop();
                if(cur == nums2)
                    return level;
                vis[cur] = true;

                for (int i = 0; i < n; ++i) 
                {
                    vector<int> v; 
                    for (int j = i; j < n; ++j) 
                    {
                        v.push_back(cur[j]);
                        vector<int> h;
                        for (int m = 0; m < n; ++m) 
                        {
                            if (m >= i && m <= j)
                                continue;
                            h.push_back(cur[m]);
                        }
                        for (int k = 0; k <= (int)h.size(); ++k) 
                        {
                            vector<int> nxt = combine(0, k - 1, h, v);
                            if (!vis.count(nxt)) 
                            {
                                vis[nxt] = true;
                                if (nxt == nums2) 
                                    return level+1;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
