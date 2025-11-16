class Solution {
public:
    int countHomogenous(string s) {

        int MOD = 1e9+7;
        int ans = 0; 
        int i = 0; 
        int sz = (int)s.size(); 
        while(i< sz)
        {
            int j = i+1; 
            while(j< s.size() && s[j] == s[i])
            {
                j++;
            }
            long long len = j-i;
            ans += ((len*(len+1))/2)%MOD;
            i= j; 
        }
        return ans;
        
    }
};