class Solution {
int fn(int city, vector<vector<int>>&dp, int day,
        vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, int &n, int &maxdays)
{
    if(day == maxdays)
        return 0;
    auto &ret = dp[city][day];
    if(ret != -1)
            return ret;
    int stay = stayScore[day][city];
    int c1 = stay + fn(city, dp, day+1, stayScore, travelScore, n, maxdays);
    for(int i = 0; i< n; i++)
        {
            if(i== city)
                continue;
            int c2 = travelScore[city][i] + fn(i, dp, day+1, stayScore, travelScore, n,maxdays);
            ret = max(ret, c2);
        }
    return ret = max(c1, ret);
}
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {


        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        int ans = 0;
        int maxdays = k;
        for(int i = 0; i< n; i++)
            {
                int _k =0;
                ans = max(ans, fn(i, dp, _k, stayScore, travelScore,n,maxdays));
            }
        
        return ans;
        
    }
};