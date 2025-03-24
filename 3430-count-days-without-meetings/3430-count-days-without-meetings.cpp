class Solution {
    
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>>v;
        int mini = INT_MAX;
        int maxi = 0; 
        for(int i = 0; i< meetings.size(); i++)
        {
           v.push_back({meetings[i][0],meetings[i][1]});
           mini = min(mini, meetings[i][0]);
           maxi = max(maxi, meetings[i][1]);
        }
        sort(v.begin(), v.end());
        int ans = 0; 

        int maxend = v[0].second; 
        for(int i = 1; i< v.size(); i++)
        {
            if(v[i].first > maxend)
            {
                ans += v[i].first - maxend-1;
            }
            maxend= max(v[i].second, maxend);
        }
        cout<<ans;
        ans += (mini-1);
        ans += (days-maxi);
        return ans;
    }
};