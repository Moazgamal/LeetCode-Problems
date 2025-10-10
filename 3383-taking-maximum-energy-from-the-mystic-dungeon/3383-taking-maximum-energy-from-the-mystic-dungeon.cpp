class Solution {
    
public:
    int maximumEnergy(vector<int>& energy, int k) {

        vector<int>dp(energy.size(),-1);
        int ans = INT_MIN; 
        for(int start = energy.size()-1; start>=energy.size()-k; start--)
        {
            int j = start;
            int acc = 0;
            while(j>=0)
            {
                acc += energy[j];
                dp[j]= acc;
                ans = max(ans, dp[j]); 
                j-=k;
            }
        }
        return ans;
        
    }
};