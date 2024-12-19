class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i< s.size(); i++)
        {
            mp[s[i]]++;
        }
        int maxi = 0; 
        unordered_set<char>st;
        for(auto x: mp)
        {
            maxi = max(maxi, x.second);
        }
        for(auto x: mp)
        {
            if(x.second == maxi)
                st.insert(x.first);
        }
        string ans = "";
        for(int i = s.size()-1; i>=0; i--)
        {
            if(st.find(s[i]) != st.end())
            {
                ans += s[i];
                st.erase(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};