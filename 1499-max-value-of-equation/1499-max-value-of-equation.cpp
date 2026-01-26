class Solution {
    struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        int x1 = a.first,  y1 = a.second;
        int x2 = b.first,  y2 = b.second;

        // case 1: first values equal
        if (x1 == x2) {
            // smaller second comes later → lower priority
            return y1 < y2;
        }
        // case 2: custom formula
        return (x2 - x1) + y1 <= y2;
    }
};
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        pq.push({points[0][0], points[0][1]});
        int ans = INT_MIN;
        for(int i = 1; i < points.size(); i++)
        {
            while(!pq.empty())
            {
                auto cur = pq.top();
                auto val = abs(cur.first-points[i][0]);
                if(val <=k)
                {
                    ans = max(ans, cur.second+points[i][1]+ val);
                    break;
                }
                else
                    pq.pop();
            }
            pq.push({points[i][0], points[i][1]});
        }
        return ans;


    }
};