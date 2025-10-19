class Solution {
    string add(string s, int a) {
        for (int i = 1; i < s.size(); i += 2)
            s[i] = ((s[i]-'0' + a) % 10) + '0';
        return s;
    }

    string rotate(string s, int b) {
        int n = s.size();
        b %= n;
        return s.substr(n - b) + s.substr(0, n - b);
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            ans = min(ans, cur);

            // العملية الأولى: add
            string added = add(cur, a);
            if (!vis.count(added)) {
                vis.insert(added);
                q.push(added);
            }

            // العملية الثانية: rotate
            string rotated = rotate(cur, b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};
