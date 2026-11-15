class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1000000007;
        int ans = 0; 
        vector<int> odds(arr.size(),0);
        vector<int> evens(arr.size(),0);
        if(arr[arr.size()-1] %2 != 0)
        {
            odds[arr.size()-1]=1;
            cout<<arr[arr.size()-1]<<"fdfd\n";
            ans++;
        }
        else
        {
            evens[arr.size()-1]=1;
        }
        for(int i = arr.size()-2; i>=0; i--)
        {
            if(arr[i] %2 != 0)
            {
                odds[i] = (evens[i+1]+1)%MOD;
                evens[i] = odds[i+1];
                ans+=odds[i];
                ans%=MOD;
                
            }
            else
            {
                evens[i]= (1+evens[i+1])%MOD;
                odds[i]= odds[i+1];
                ans+=odds[i];
                ans %=MOD;
            }
            
        }
        
        return ans;
        
    }
};