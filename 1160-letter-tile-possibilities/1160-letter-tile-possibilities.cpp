class Solution {
    void backtracking(int idx,int &sz, int &ans, unordered_map<char,int>&mp)
    {
        if(idx >= sz)
            return ;
        for(auto x: mp)
        {
            if(x.second ==0)
                continue;
            mp[x.first]--;
            ans++;
            backtracking(idx+1, sz, ans, mp);
            mp[x.first]++;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int ans = 0; 
        unordered_map<char,int>mp;
        for(int i = 0; i< tiles.size(); i++)
            mp[tiles[i]]++;
        int sz = tiles.size();
        backtracking(0,sz,ans,mp);
        return ans;
        
    }
};