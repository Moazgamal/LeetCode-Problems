class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        for(int i = 0; i< s.size(); i++)
        {
            ans.push_back(s[i]);
            if(ans.size() >= part.size())
            {
                int sz = ans.size();
                int psz= part.size();
                int diff = sz- psz;
                if(ans.substr(diff, psz) == part)
                {
                    while(psz--)
                        ans.pop_back();
                }
            }
        }return ans;
        
    }
};