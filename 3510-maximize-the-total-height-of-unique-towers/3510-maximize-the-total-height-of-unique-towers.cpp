class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long ans = 0; 

        sort(maximumHeight.begin(), maximumHeight.end());
         ans=maximumHeight[maximumHeight.size()-1];
        int x=maximumHeight[maximumHeight.size()-1];

        for(int i = maximumHeight.size()-2; i>=0; i--)
        {
            
            if(maximumHeight[i] >= x)
            {
                if(x-1 ==0)
                    return -1;
                ans+=(x-1);
                x=x-1;
            }
            else
            {
                ans+=maximumHeight[i];
                x=maximumHeight[i];
                
            }
            
        }
        
        return ans;

        
    }
};