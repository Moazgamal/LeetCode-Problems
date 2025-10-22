class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));

        // ******************** صفوف ********************
        unordered_map<int, unordered_set<int>> mp;
        unordered_map<int, int> indegree;

        for (auto &p : rowConditions) {
            int from = p[0], to = p[1];
            if (mp[from].insert(to).second)
                indegree[to]++;
        }

        for (int i = 1; i <= k; i++) {
            if (!mp.count(i)) mp[i] = {};
            if (!indegree.count(i)) indegree[i] = 0;
        }

        queue<int> q;
        for (int i = 1; i <= k; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topoRow;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            topoRow.push_back(cur);
            for (auto nxt : mp[cur]) {
                if (--indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        if ((int)topoRow.size() != k) return {}; // cycle

        unordered_map<int,int> rows;
        for (int i = 0; i < k; i++) rows[topoRow[i]] = i; // unique row per number

        // ******************** أعمدة ********************
        unordered_map<int, unordered_set<int>> mpp;
        unordered_map<int, int> indegree2;

        for (auto &p : colConditions) {
            int from = p[0], to = p[1];
            if (mpp[from].insert(to).second)
                indegree2[to]++;
        }

        for (int i = 1; i <= k; i++) {
            if (!mpp.count(i)) mpp[i] = {};
            if (!indegree2.count(i)) indegree2[i] = 0;
        }

        queue<int> q1;
        for (int i = 1; i <= k; i++)
            if (indegree2[i] == 0)
                q1.push(i);

        vector<int> topoCol;
        while (!q1.empty()) {
            int cur = q1.front(); q1.pop();
            topoCol.push_back(cur);
            for (auto nxt : mpp[cur]) {
                if (--indegree2[nxt] == 0)
                    q1.push(nxt);
            }
        }

        if ((int)topoCol.size() != k) return {}; // cycle

        unordered_map<int,int> cols;
        for (int i = 0; i < k; i++) cols[topoCol[i]] = i; // unique col per number

        // ******************** بناء المصفوفة ********************
        for (int i = 1; i <= k; i++) {
            int rr = rows[i];
            int cc = cols[i];
            ans[rr][cc] = i;
        }

        return ans;
    }
};

