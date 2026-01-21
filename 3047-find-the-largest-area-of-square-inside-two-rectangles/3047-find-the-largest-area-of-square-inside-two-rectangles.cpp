class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        vector<pair<pair<int,int>, int>>v;
        long long maxArea = 0; 
        for(int i = 0; i< bottomLeft.size(); i++)
        {
            v.push_back({{bottomLeft[i][0],bottomLeft[i][1]},i});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++)
        {
            for(int j = i+1; j< v.size(); j++)
            {
                int x1 = v[i].first.first;
                int y1 = v[i].first.second;
                int x2 = v[j].first.first;
                int y2 = v[j].first.second;
                int yend1 = topRight[v[i].second][1];
                int xend1 = topRight[v[i].second][0];
                int yend2 = topRight[v[j].second][1];
                int xend2 = topRight[v[j].second][0];
                if(y2<yend1 && yend2 > y1 && x2<xend1)
                {
                    int dim1 = min(xend1,xend2)-x2;
                    int dim2 = min(yend1,yend2)-max(y1,y2);
                    int mini = min(dim1, dim2);
                    // cout<<dim1<<" "<<dim2<<" "<<i<<" "<<j<<"\n";
                    maxArea = max(maxArea, (long long)mini*mini);
                }
            }
        }
        return maxArea;
    }
};