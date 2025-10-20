class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>> v;
        for (int i = 0; i < courses.size(); i++) {
            v.push_back({courses[i][1], courses[i][0]}); // {lastDay, duration}
        }

        sort(v.begin(), v.end()); // sort by lastDay ascending

        priority_queue<int> pq; // نخزن فيه الدورات اللي أخدناها (مدتها)
        int total = 0;

        for (int i = 0; i < v.size(); i++) {
            int duration = v[i].second;
            int end = v[i].first;
            total += duration;
            pq.push(duration);

            // لو المجموع عدى الـ deadline
            if (total > end) {
                total -= pq.top(); // شيل أطول كورس
                pq.pop();
            }
        }

        return pq.size();
    }
};
