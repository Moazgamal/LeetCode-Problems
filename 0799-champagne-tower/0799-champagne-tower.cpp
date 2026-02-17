class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        int maxRow = query_row+2;
        vector<vector<pair<double,double>>>v(maxRow);
        v[0].push_back({poured,0});
        for(int r = 0; r <= query_row; r++)
        {
            for(int j = 0; j < v[r].size(); j++)
            {
                double po = v[r][j].first;
                if(po >1)
                {
                    double rest = (po-1)/2.0;
                    v[r][j].first = 1.0;
                    if(j == 0)
                    {
                        v[r+1].push_back({rest,0});
                        v[r+1].push_back({rest,0});
                    }
                    else
                    {
                        v[r+1][j].first += rest;
                        v[r+1].push_back({rest, 0});
                    }
                }
                else
                {
                    if(j == 0)
                    {
                        v[r+1].push_back({0,0});
                        v[r+1].push_back({0,0});
                    }
                    else
                        v[r+1].push_back({0, 0});
                }
            }
        }
        return v[query_row][query_glass].first;
        
    }
};