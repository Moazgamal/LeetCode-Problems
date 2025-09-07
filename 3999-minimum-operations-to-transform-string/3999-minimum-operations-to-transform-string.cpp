class Solution {
public:
    int minOperations(string s) {
        vector<int>v(26,0);
        for(int i = 0; i < s.size(); i++)
        {
            v[s[i]-'a']++;
        }
        int ans = 0; 
        int last = 0; 
        int lastidx = -1; 
        for(int i = 1; i< v.size(); i++)
        {
            if(v[i] != 0)
            {
                if(lastidx != -1)
                {
                    ans += i-lastidx;
                    last += v[i];
                    lastidx = i; 
                }
                else
                {
                    last += v[i];
                    lastidx = i; 
                }
            }
        }
        if(lastidx!=-1)
            ans += (25-lastidx+1);
        return ans; 
        
        
    }
};