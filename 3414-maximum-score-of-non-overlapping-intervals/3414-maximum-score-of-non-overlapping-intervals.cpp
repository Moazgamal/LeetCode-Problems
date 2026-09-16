class Solution {
    pair<long long, vector<int>> fn(
        int IDX,
        int rest,
        vector<pair<pair<int,int>,pair<long long,int>>>& v,
        vector<vector<pair<long long, vector<int>>>>& Dp,
        vector<int>& IND)
    {
        // no more intervals or no more choices
        if (IDX >= v.size() || rest == 0)
            return {0, {}};

        pair<long long, vector<int>>& ret = Dp[IDX][rest];

        if (ret.first != -1)
            return ret;

        // pick
        int nextIDX = IND[IDX];

        pair<long long, vector<int>> pick = {0, {}};

        if (nextIDX != -1)
            pick = fn(nextIDX, rest - 1, v, Dp, IND);

        pick.first += v[IDX].second.first;
        pick.second.push_back(v[IDX].second.second);

        // leave
        pair<long long, vector<int>> leave = {0, {}};

        if (IDX + 1 < v.size())
            leave = fn(IDX + 1, rest, v, Dp, IND);

        sort(pick.second.begin(), pick.second.end());
        sort(leave.second.begin(), leave.second.end());

        if (leave.first < pick.first)
            return ret = pick;

        if (leave.first > pick.first)
            return ret = leave;

        // same score
        if (pick.second < leave.second)
            return ret = pick;

        return ret = leave;
    }

    int BS(
        vector<pair<pair<int,int>,pair<long long,int>>>& v,
        int start,
        int enD,
        int target)
    {
        int pos = -1;

        while (start <= enD)
        {
            int miD = start + (enD - start) / 2;

            if (v[miD].first.first > target)
            {
                pos = miD;
                enD = miD - 1;
            }
            else
            {
                start = miD + 1;
            }
        }

        return pos;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        vector<pair<pair<int,int>,pair<long long,int>>> v;

        for (int i = 0; i < intervals.size(); i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            long long w = intervals[i][2];

            v.push_back({{s, e}, {w, i}});
        }

        sort(v.begin(), v.end());

        vector<int> IND(intervals.size());

        int lastEnd = -1;

        for (int i = 0; i < v.size(); i++)
        {
            int end = v[i].first.second;

            if (lastEnd == end)
            {
                IND[i] = IND[i - 1];
            }
            else
            {
                IND[i] = BS(
                    v,
                    i + 1,
                    (int)v.size() - 1,
                    end
                );
            }

            lastEnd = end;
        }

        pair<long long, vector<int>> empty = {-1, {}};

        vector<vector<pair<long long, vector<int>>>> Dp(
            intervals.size(),
            vector<pair<long long, vector<int>>>(5, empty)
        );

        // IMPORTANT: up to 4 intervals
        vector<int> ans = fn(0, 4, v, Dp, IND).second;

        return ans;
    }
};