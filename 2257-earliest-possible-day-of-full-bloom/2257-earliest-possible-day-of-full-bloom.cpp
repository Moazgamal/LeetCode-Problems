class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {


        vector<pair<int,int>>v;
        for(int i = 0; i< plantTime.size(); i++)
        {
            int first = plantTime[i]; int second = growTime[i];
            v.push_back({second, first});
        }
        sort(v.rbegin(), v.rend());
       int curDay = 0; 
        for(int i = 0; i< v.size(); i++)
        {
            curDay += v[i].second;
        }
        vector<int>vv(v.size(), 0);
        int dis = v[v.size()-1].second;
        for(int i = v.size()-2; i>=0; i--)
        {
            vv[i] = dis;
            dis += v[i].second;
        }
        int extra = 0; 
        for(int i = 0; i< v.size(); i++)
        {
            int diff = (v[i].first - vv[i]);
            if(diff>0)
            {
                extra = max(diff, extra);
            }
        }
        return extra + curDay ;
        
    }
};