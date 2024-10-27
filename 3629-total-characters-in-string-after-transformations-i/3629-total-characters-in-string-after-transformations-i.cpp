class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1000000007;
        vector<int>v(26,0);
        for(int i = 0; i< s.size(); i++)
            {
                v[s[i]-'a']++;
            }
        

        for(int i =0; i< t; i++)
            {
                int mpz= v[25];
                for(int j = 25; j>0; j--)
                    {
                        v[j] = v[j-1]%MOD;
                    }
                v[0] = mpz%MOD; v[1] += mpz%MOD;
            }
         int ans = 0; 
        for(int i =0; i< v.size(); i++)
            {
                ans = ans%MOD + (v[i]%MOD)%MOD;
            }return ans%MOD;
        
        
    }
};