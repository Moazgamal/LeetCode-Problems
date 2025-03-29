class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalones = 0; 
        for(int i = 0; i< s.size();i++)
            {
                if(s[i] == '1')
                    totalones++;
            }
        int ans = totalones;
        vector<int> v(s.size(),0);
        vector<int> v2(s.size(), 0);
        int zeros = 0; 
        for(int i =0; i< s.size(); i++)
            {
                v[i] = zeros;
                if(s[i]=='0')
                    zeros++;
                else
                    zeros=0;
            }
        zeros=0;
        for(int i = s.size()-1; i>=0; i--)
            {
                v2[i] = zeros;
                if(s[i] == '0')
                    zeros++;
                else
                    zeros=0;
            }
        for(int i = 0; i< s.size(); )
            {
                
                if(s[i] == '1')
                {
                    int j = i+1; 
                    while(j< s.size() && s[j] == '1')
                        j++;
                        
                    if(j< s.size() && i> 0)
                        ans = max(ans, totalones+v[i]+v2[j-1]);
                    
                    i=j;
                }
                else
                    i++;
            }
        return ans;
        
    }
};