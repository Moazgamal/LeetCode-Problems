class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));

        auto topo = [&](vector<vector<int>>& conds, unordered_map<int,int>& pos) -> bool {
            unordered_map<int, unordered_set<int>> mp;
            unordered_map<int, int> indegree;

            // بناء الجراف
            for (auto &v : conds) {
                int from = v[0], to = v[1];
                if (mp[from].insert(to).second)
                    indegree[to]++;
            }

            // ✅ نضيف كل الأرقام من 1 إلى k حتى لو مش ظهرت
            for (int i = 1; i <= k; i++) {
                if (!mp.count(i)) mp[i] = {};
                if (!indegree.count(i)) indegree[i] = 0;
            }

            queue<int> q;
            for (int i = 1; i <= k; i++) {
                if (indegree[i] == 0)
                    q.push(i);
            }

            int idx = 0; // ده هيبقى ترتيب الرقم (row أو col)
            vector<int> order;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                order.push_back(cur);
                for (auto nxt : mp[cur]) {
                    if (--indegree[nxt] == 0)
                        q.push(nxt);
                }
            }

            // ✅ اكتشاف cycle لو الحجم مش كامل
            if (order.size() != k)
                return false;

            // حفظ ترتيب الموضع
            for (int i = 0; i < k; i++)
                pos[order[i]] = i;

            return true;
        };

        unordered_map<int, int> rows, cols;

        // ترتيب الصفوف والأعمدة
        if (!topo(rowConditions, rows)) return {};
        if (!topo(colConditions, cols)) return {};

        // بناء المصفوفة النهائية
        for (int i = 1; i <= k; i++) {
            ans[rows[i]][cols[i]] = i;
        }

        return ans;
    }
};
