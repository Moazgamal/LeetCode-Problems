class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[values.size()-1];
        int ans = 0; 
        for(int i = values.size()-2; i >=0 ; i--)
        {
            maxi--;
            ans = max(ans, values[i] + maxi);
            maxi = max(maxi, values[i]);
        }
        return ans;
        
    }
};