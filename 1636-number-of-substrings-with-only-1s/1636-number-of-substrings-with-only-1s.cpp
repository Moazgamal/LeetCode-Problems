class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9+7;
        int ans = 0; 
        int i = 0; 
        int sz = (int)s.size(); 
        while(i< sz)
        {
            int j = i; 
            if(s[i] == '1')
            {
                int j = i+1; 
                while(j< s.size() && s[j] == '1')
                {
                    j++;
                }
                long long len = j-i;
                ans += ((len*(len+1))/2)%MOD;
                i= j; 
            } 
            else
                i++;
        }
        return ans; 
        
    }
};