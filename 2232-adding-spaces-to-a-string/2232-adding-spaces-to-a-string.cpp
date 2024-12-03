class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        unordered_map<int,int>mp;
        for(int i =0; i< spaces.size(); i++)
        {
            mp[spaces[i]]++;
        }
        string ans = "";
        if(mp.count(0)>0)
            ans.push_back(' ');
        for(int i = 0; i< s.size(); i++)
        {
            if(mp.count(i+1)>0 && i+1 != s.size())
            {
                ans+=(s[i]);
                ans+=(' ');
            }
            else
            {
                ans+=(s[i]);
            }
        }return ans;
        
    }
};