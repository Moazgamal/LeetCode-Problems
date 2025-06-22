class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int sz = coords.size();
        unordered_map<int, vector<int>> x;
        unordered_map<int, vector<int>>y;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        int miny = INT_MAX;
        int maxy = INT_MIN;
        for(int i = 0; i< coords.size(); i++)
            {
                x[coords[i][0]].push_back(coords[i][1]);
                y[coords[i][1]].push_back(coords[i][0]);
                minx = min(minx, coords[i][0]);
                maxx = max(maxx, coords[i][0]);
                miny = min(miny, coords[i][1]);
                maxy = max(maxy, coords[i][1]);
            }
        long long maxi = 0; 
        for(auto h: x)
            {
                int n = h.second.size();
                if(n<2)
                    continue;
                sort(h.second.begin(), h.second.end());
                long long b = abs(h.second[0]-h.second[h.second.size()-1]);
                long long he = max(abs(h.first-minx), abs(h.first-maxx));
                if(b!=0 && he!=0)
                    maxi= max(maxi, b*he);
                    
            }
        for(auto h: y)
            {
                int n = h.second.size();
                if(n<2)
                    continue;
                sort(h.second.begin(), h.second.end());
                long long b = abs(h.second[0]-h.second[h.second.size()-1]);
                long long he = max(abs(h.first-miny),abs(h.first-maxy));
                if(b !=0 && he !=0)
                    maxi = max(maxi, b*he);
                   
            }
        if(maxi>0)
            return maxi;
        return -1;
        
    }
};