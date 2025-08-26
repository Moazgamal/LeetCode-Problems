class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea = 0; 
        double maxdiag = 0; 
        for(int i = 0; i< dimensions.size(); i++)
        {
            int len = dimensions[i][0]; 
            int wid = dimensions[i][1];
            double diag = sqrt(len*len+wid*wid);
            int area = len*wid;
            if(diag< maxdiag)
                continue;
            else if(diag > maxdiag)
            {
                maxdiag = diag;
                maxarea = area;
            }
            else
            {
                if(area > maxarea)
                {
                    maxarea = area;
                    maxdiag = diag;
                }
            }
        }
        return maxarea;
        
    }
};