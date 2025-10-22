class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));

        auto topo = [&](vector<vector<int>>& conds) -> vector<int> {
            unordered_map<int, unordered_set<int>> g;
            unordered_map<int, int> indeg;
            for (auto& e : conds) {
                if (g[e[0]].insert(e[1]).second)
                    indeg[e[1]]++;
            }

            // \U0001f527 أضف كل الأرقام من 1 إلى k (حتى لو مفيهاش شروط)
            for (int i = 1; i <= k; i++) {
                if (!g.count(i)) g[i] = {};
                if (!indeg.count(i)) indeg[i] = 0;
            }

            queue<int> q;
            for (int i = 1; i <= k; i++) {
                if (indeg[i] == 0)
                    q.push(i);
            }

            vector<int> order;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                order.push_back(cur);
                for (auto nxt : g[cur]) {
                    indeg[nxt]--;
                    if (indeg[nxt] == 0)
                        q.push(nxt);
                }
            }

            if (order.size() != k) return {}; // cycle detected
            return order;
        };

        // \U0001f9ed احسب ترتيب الصفوف والأعمدة
        vector<int> rowOrder = topo(rowConditions);
        vector<int> colOrder = topo(colConditions);
        if (rowOrder.empty() || colOrder.empty()) return {};

        unordered_map<int, int> rows, cols;
        for (int i = 0; i < k; i++) {
            rows[rowOrder[i]] = i;
            cols[colOrder[i]] = i;
        }

        // \U0001f527 ضع كل رقم في مكانه الصحيح
        for (int i = 1; i <= k; i++) {
            int r = rows[i];
            int c = cols[i];
            ans[r][c] = i;
        }

        return ans;
    }
};
