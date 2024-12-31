class Solution {
    int fn(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        
        auto &ret = dp[idx];
        if(ret != INT_MAX)
            return ret;
        auto it1 = upper_bound(days.begin() + idx, days.end(), days[idx]);
        auto it2 = upper_bound(days.begin()+idx, days.end(), days[idx]+6);
        auto it3 = upper_bound(days.begin()+idx, days.end(), days[idx]+29);
        int cost1= costs[0];
        if(it1 != days.end())
            cost1 += fn(it1-days.begin(), days, costs, dp);
        int cost2 = costs[1];
        if(it2 != days.end())
            cost2 += fn(it2-days.begin(), days, costs, dp);
        int cost3 = costs[2];
        if(it3 != days.end())
            cost3 += fn(it3-days.begin(), days, costs, dp);
        return ret = min(cost1, min(cost2,cost3));

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),INT_MAX);
        return fn(0, days, costs, dp);
        
    }
};