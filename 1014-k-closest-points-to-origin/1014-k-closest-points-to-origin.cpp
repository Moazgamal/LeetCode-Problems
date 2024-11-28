class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int sz = sqrt(10001*10001+10001*10001);
        map<double,vector<int>>mp;
        for(int i = 0; i< points.size(); i++)
        {
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            mp[dist].push_back(i);
        }
        vector<vector<int>> result;
        for(auto x: mp)
        {
            for(auto y : x.second)
            {
                if(result.size()==k)
                    break;
                result.push_back(points[y]);
            }
        }
        return result;
        
    }
};