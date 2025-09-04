class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        unordered_map<int, set<int>> x;
        unordered_map<int, set<int>> y;
        sort(points.begin(), points.end());
        for(int i = 0; i< points.size(); i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            x[x1].insert(y1);
            y[y1].insert(x1);
        }
        int ans = 0; 
        
        for(int i = 0; i< points.size(); i++)
        {
            int x1 = points[i][0]; int y1 = points[i][1];
            auto it1 = x[x1].find(y1);
            auto it2 = y[y1].find(x1);
            int val1 = INT_MAX; int val2 = INT_MAX; int val3 = INT_MAX; 
            if(it1 != x[x1].end())
            {
                auto nxt = next(it1);
                if(nxt != x[x1].end())
                {
                    val1 = *nxt;
                }
            }
            if(it2 != y[y1].end() && it2 != y[y1].begin())
            {
                auto nxt = prev(it2);
                if(nxt != y[y1].end())
                {
                    val2 = *nxt;
                }
            }
            if(val1 != INT_MAX)
                ans++;
            if(val2 != INT_MAX)
                ans++;
            
            if((val1 != INT_MAX && val1 == y1+1) || (val2 != INT_MAX && val2 == x1-1))
                continue;
            int ylimit = INT_MAX; int xlimit = INT_MAX; int ylimit2 = INT_MAX; 
            int xlimit2 = INT_MAX; 
            if(val1 != INT_MAX)
                ylimit = val1;
            if(val2 != INT_MAX)
                xlimit = val2;
            for(int j = i-1; j>=0; j--)
            {
                if(xlimit != INT_MAX && points[j][0] <= xlimit)
                    break;
                if(points[j][1] <= y1)
                    continue;
                if(ylimit != INT_MAX)
                {
                    if(points[j][1] >= ylimit)
                        continue;
                    if(ylimit2 != INT_MAX)
                    {
                        if(points[j][1] >=  ylimit2)
                            continue;
                        ylimit2 = points[j][1];
                    }
                    if(xlimit2 == points[j][0])
                        continue;
                    ans++; 
                    ylimit2 = points[j][1];
                    xlimit2 = points[j][0];
                }
                else
                {
                    if(ylimit2 != INT_MAX)
                    {
                        if(points[j][1] >=  ylimit2)
                            continue;
                        ylimit2 = points[j][1];
                    }
                    if(xlimit2 == points[j][0])
                        continue;
                    ans++; 
                    ylimit2 = points[j][1];
                    xlimit2 = points[j][0];
                }
            }
           
        }
        return ans;
        
    }
};