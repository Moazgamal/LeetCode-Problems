class Solution {
public:
    int longestContinuousSubstring(string s) {

        int ans = 0; 
        int cnt = 0; 
        
        for(int i = 0; i< s.size()-1; i++)
        {
            if(s[i+1] == s[i]+1)
            {
                cnt++;
                ans = max(ans, cnt+1);
            }
            else
                cnt= 0; 
        }return ans>1?ans:1;
        
    }
};