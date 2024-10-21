class Solution {
    int backtracking(int idx, string &s, unordered_map<string,int>&mp)
    {
        int ans = 0; 
        string x = "";
        for(int i = idx; i< s.size(); i++)
        {
            x+= s[i];
            if(mp.count(x)==0)
            {   mp[x]++;
                ans= max(ans, 1+ backtracking(i+1, s, mp));
                mp.erase(x);
            }
           
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_map<string, int> mp;
        return backtracking(0,s, mp);
        
    }
};