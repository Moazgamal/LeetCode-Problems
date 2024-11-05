class Solution {
public:
    int minChanges(string s) {
        
        int ans = 0;
        for(int i = 0; i< s.size();i++)
        {
            if(s[i] == s[i+1])
            {
                i++;
            }
            else
            {
                s[i+1] = s[i];
                i++; ans++;
            }
        }return ans;
    }
};