class Solution {
    
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int i = 0; 
        int sz = (int)prices.size();
        while(i < sz)
        {
            int j = i+1; 
            while(j < sz && prices[j] == prices[j-1]-1)
            {
                j++;
            }
            ans += ((long long)(j-i)*(j-i+1))/2;
            i=j;
        }return ans;
    }
};