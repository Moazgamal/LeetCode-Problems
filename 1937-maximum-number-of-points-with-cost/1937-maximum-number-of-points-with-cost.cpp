class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>>point(points.size(), vector<long long>(points[0].size(), 0));
        for(int r = 0; r< points.size(); r++)
        {
            for(int c = 0; c< points[0].size(); c++)
            {
                point[r][c] = points[r][c];
            }
        }
        if(points.size()==1)
        {
            long long ans = INT_MIN;
            for(int i = 0; i< point[0].size(); i++)
                ans = max(ans, point[0][i]);
            return ans;
        }
        long long ans = LLONG_MIN;

        for(int r = points.size()-1; r >= 1; r--)
        {
            long long maxiSoFar = INT_MIN;
            vector<long long>v(points[0].size(),0);
            int cnt = 0; 
            for(int c = 0; c < points[0].size(); c++)
            {
                if(maxiSoFar == INT_MIN)
                {
                    maxiSoFar = point[r][c];
                    v[c]=maxiSoFar;
                    cnt++;
                    continue;
                }
                v[c] = max(point[r][c], maxiSoFar-cnt);
                if(point[r][c] >= maxiSoFar-cnt)
                {
                    maxiSoFar = max(maxiSoFar-cnt, point[r][c]);
                    cnt=1;
                }
                else
                {
                    // maxiSoFar = max(maxiSoFar-cnt, points[r][c]);
                    cnt++;
                }

            }
            maxiSoFar = INT_MIN;
            cnt=0;
            
            for(int c = points[0].size()-1; c >= 0; c--)
            {
                if(maxiSoFar == INT_MIN)
                {
                    maxiSoFar = point[r][c];
                    cout<<maxiSoFar<<" ";
                    v[c]=max(v[c], maxiSoFar);
                    point[r-1][c] += v[c];
                    if(r-1 ==0)
                        ans = max(ans, point[r-1][c]);
                    cnt++;
                    continue;
                }
                
                v[c] = max(v[c], max(point[r][c], maxiSoFar-cnt));
                point[r-1][c] += v[c];
                if(r-1 == 0)
                    ans = max(ans, point[r-1][c]);
                if(point[r][c] >= maxiSoFar-cnt)
                {
                    maxiSoFar = max(maxiSoFar-cnt, point[r][c]);
                    cnt=1;
                }
                else
                {
                    // maxiSoFar = max(maxiSoFar-cnt, points[r][c]);
                    cnt++;
                }
                // cout<<maxiSoFar<<" "<<cnt<<" \n";
            }
            
        }
        return ans; 
        
    }
};