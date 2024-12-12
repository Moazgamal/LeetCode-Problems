class Solution {
pair<int,int> fn(vector<vector<int>>&points, int x, int y)
{
    pair<int,int> p = make_pair(200000,200000);
    for(int i = 0; i< points.size(); i++)
        {
            if(points[i][0] == x)
            {
                if(points[i][1] > y)
                    return {points[i][0], points[i][1]};
            }
        }return p;
}
pair<int,int> fn2(vector<vector<int>>&points, int x, int y)
{
     pair<int,int> p = make_pair(200000,200000);
    for(int i = 0; i< points.size(); i++)
        {
            if(points[i][1] == y)
            {
                if(points[i][0] > x)
                    return {points[i][0], points[i][1]};
            }
        }return p;

}
public:
    int maxRectangleArea(vector<vector<int>>& points) {

        sort(points.begin(), points.end());
        int ans = -1;
        map<int,set<int>>mp;
        for(int i = 0; i< points.size(); i++)
            {
                mp[points[i][0]].insert(points[i][1]);
            }
        for(int i =0; i< points.size()-1; i++)
            {
                int x = points[i][0];
                int y = points[i][1];
                int j = i+1; int x2=-1;
                while(j< points.size())
                    {
                        if(points[j][0]>points[i][0] && points[j][1] == points[i][1])
                        {
                            x2 = points[j][0]; break;
                        }
                        j++;
                    }
                if(x2==-1)
                    continue;
                j = i+1;
                if(points[j][0] != points[i][0])
                    continue;
                int y2 = points[j][1];
                if(mp[x2].find(y2) == mp[x2].end())
                    continue;
                j = i+1; bool s = false;
                while(j< points.size())
                    {
                        if(points[j][0] > x && points[j][0] < x2 && points[j][1] > y && points[j][1] < y2)
                        {
                            s = true; break;
                        }j++;
                    }
                if(s)
                    continue;
                if(fn(points, x2,y) != fn2(points, x, y2))
                    continue;
                ans = max(ans, (x2-x)*(y2-y));
                
                
            }
        return ans;
        
        
    }
};