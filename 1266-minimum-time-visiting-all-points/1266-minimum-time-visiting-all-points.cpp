class Solution {
    int calcDest(int sourceX, int sourceY, int destX, int destY)
    {
        int diffX = abs(sourceX-destX);
        int diffY = abs(sourceY-destY);
        if(diffX== diffY)
            return diffX;
        if(diffX>diffY)
            return diffY+(diffX-diffY);
        return diffX+(diffY-diffX);
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0; 
        for(int i = 0; i< points.size()-1; i++)
        {
            int m = calcDest(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
            ans += m; 
        }
        return ans;
    }
};