class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        
        long long ans = 0;
        for(int i = 0; i< strategy.size(); i++)
            ans += (strategy[i]*prices[i]);

        long long acc = 0; 
        int i = 0; int j = (i+k)-1;

        for(int u = j+1; u < strategy.size(); u++)
            acc += strategy[u]* prices[u];
        
       int m1 = i + (k/2); int m2 = j;
        while(m1 <= m2)
        {
            acc += prices[m1];
            m1++;
        }
        ans = max(ans, acc);
        
        j = k-1; i = 0;
        int f = k/2;
        while(j+1 < strategy.size())
        {
            int left = strategy[i]; 

            acc += (left*prices[i]);
            
            if(strategy[j+1]== -1)
                acc += (2*prices[j+1]);
            
            else if(strategy[j+1]==0)
                acc += prices[j+1];

            acc -= (prices[f]);
            ans = max(ans, acc); 
            f++; j++; i++;
        }
        return ans; 
        
    }
};