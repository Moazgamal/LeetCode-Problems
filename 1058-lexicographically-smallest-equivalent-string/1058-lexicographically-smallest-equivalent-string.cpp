class Solution {
    void dfs(char c, unordered_map<char,unordered_set<char>>&mp2,  vector<bool>&vis,
    char &mini){
        vis[c-'a'] = true;
        for(auto x: mp2[c])
        {
            if(!vis[x-'a'])
            {
                mini = min(mini, x);
                dfs(x, mp2, vis, mini);
            }
        }

            
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

       
       unordered_map<char,unordered_set<char>>mp2;
        for(int i = 0; i< s1.size(); i++)
        {
            
            mp2[s1[i]].insert(s2[i]);
            mp2[s2[i]].insert(s1[i]);
           
        }
        for(int i = 0; i< baseStr.size(); i++)
        {
            vector<bool> vis(26, false);
            char mini = baseStr[i];
            dfs(baseStr[i],mp2, vis, mini);
            baseStr[i] = mini;
        }
        return baseStr;
        
    }
};