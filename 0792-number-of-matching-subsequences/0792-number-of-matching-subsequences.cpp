class Solution {
    bool dfs(int idx, string &str, vector<vector<int>>&v, int lastidx)
    {
        if(idx == str.size())
            return true;
        if(v[str[idx]-'a'].size() == 0)
            return false; 
        auto it = upper_bound(v[str[idx]-'a'].begin(), 
        v[str[idx]-'a'].end(), lastidx);
        if(it == v[str[idx]-'a'].end())
            return false;
        return dfs(idx+1, str, v, *it);
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>>v(26);
        for(int i = 0; i< s.size(); i++)
            v[s[i]-'a'].push_back(i);
        int ans = 0; 
        for(int i = 0; i< words.size(); i++)
        {
            if(dfs(0,words[i], v, -1))
                ans++;
        }
        return ans;
    }
};