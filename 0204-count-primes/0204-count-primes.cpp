class Solution {
public:
    int countPrimes(int n) {
        vector<int>v(n,true);
        for(int i = 2; i*i<n; i++)
        {
            if(v[i] == false)
                continue;
            for(int j = i+i ; j<n; j+=i)
            {
                v[j] =false;
            }
        }
        int ans = 0 ; 
        for(int i = 2 ; i< v.size(); i++)
        {
            if(v[i] == true)
            {
                ans++;
            }
        }return ans;
    }
};