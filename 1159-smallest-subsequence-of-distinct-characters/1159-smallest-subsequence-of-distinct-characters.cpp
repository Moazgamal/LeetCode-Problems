class Solution {
    bool fn(map<char,vector<int>>&mp, unordered_map<char,bool>&vis,string &ans,
    int lastidx)
    {
        if(ans.size() == mp.size())
        {
            return true; 
        }
        for(auto &x: mp)
        {
            if(vis[x.first] == false)
            {
                auto u = upper_bound(mp[x.first].begin(), mp[x.first].end(),
                lastidx);
                if(u == x.second.end())
                {
                    return false;
                }
                vis[x.first] = true; 
                ans.push_back(x.first);
                bool n = fn(mp, vis, ans, *u);
                if(n == true)
                    return true; 
                vis[x.first] = false;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string smallestSubsequence(string s) {
        
        unordered_map<char,bool>vis;
        map<char,vector<int>>mp;
        for(int i = 0; i< s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        string ans = "";
        fn(mp, vis, ans, -1);
        return ans; 
    }
};