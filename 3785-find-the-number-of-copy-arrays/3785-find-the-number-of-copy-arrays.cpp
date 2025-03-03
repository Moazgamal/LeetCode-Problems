class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        if(original.size() ==1)
        {
            return bounds[0][1]-bounds[0][0]+1;
        }
        long long ans = INT_MAX; 
        long long mini = -1;
        long long maxi = -1;
        for(int i = 1; i< original.size(); i++)
        {
            int diff = original[i]-original[i-1];
            long long x = bounds[i][0];
            long long y = bounds[i][1];
            if(mini == -1 && maxi == -1)
            {
                mini =  bounds[i-1][0]+diff;
                maxi = bounds[i-1][1]+diff;
            }
            else
            {
                mini= mini+diff;
            maxi = maxi+diff;
            }
            long long w = abs(x-mini) + abs(y-maxi);
            long long sum = ((y-x+1) + (maxi-mini+1));
            sum-= w; sum/=2;
            ans = min(ans, sum);
            
                mini = max(mini, x);
            maxi = min(maxi, y);
            
        }
        return ans <= 0 ? 0 : ans; 
        
    }
};