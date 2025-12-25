class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0 ;
        sort(happiness.rbegin(), happiness.rend());
        int cnt = 0; 
        while(k--)
        {
            if(happiness[cnt]-cnt>0)
                ans += happiness[cnt]-cnt;
            else
                return ans; 
            cnt++;
        }return ans; 
        
    }
};