class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        double ans = 0; 
        vector<vector<double>>v(points.size(), vector<double>(points.size(),-1));
        vector<unordered_map<double,int>>vv(points.size());
        for(int i = 0; i< points.size()-1; i++)
        {
            for(int  j = i+1; j< points.size(); j++)
            {
                double dis = sqrt(
                (abs(points[i][0]-points[j][0]))*(abs(points[i][0]-points[j][0]))
                +
                (abs(points[i][1]-points[j][1]))*(abs(points[i][1]-points[j][1]))
                );
                v[i][j] = dis; v[j][i]= dis;
                vv[i][dis]++;
                vv[j][dis]++;
            }
        }

        for(int i = 0; i< points.size(); i++)
        {
            for(int j = 0; j< points.size(); j++)
            {
                if(i == j)
                    continue;
                double dis1 = v[i][j];
                int num1 = vv[j][dis1]-1;
                    ans+= num1;
            }
            
        }
        return ans;
        
    }
};