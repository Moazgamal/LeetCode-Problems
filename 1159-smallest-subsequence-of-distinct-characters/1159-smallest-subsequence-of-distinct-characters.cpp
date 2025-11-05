class Solution {
    bool fn(vector<vector<int>>&mp, vector<bool>&vis,string &ans,
    int lastidx, int &sz)
    {
        if(ans.size() == sz)
        {
            return true; 
        }
        for(int i = 0; i< mp.size(); i++)
        {
            if(mp[i].size() == 0)
                continue;
            if(vis[i] == false)
            {
                auto u = upper_bound(mp[i].begin(), mp[i].end(),
                lastidx);
                if(u == mp[i].end())
                {
                    return false;
                }
                vis[i] = true; 
                ans.push_back(i+'a');
                bool n = fn(mp, vis, ans, *u, sz);
                if(n == true)
                    return true; 
                vis[i] = false;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string smallestSubsequence(string s) {
        
        vector<bool>vis(26, false);
        vector<vector<int>>mp(26);
        int sz = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(mp[s[i]-'a'].size()==0)
            {
                sz++;
            } 
            mp[s[i]-'a'].push_back(i);
        }
        string ans = "";
        fn(mp, vis, ans, -1, sz);
        return ans; 
    }
};