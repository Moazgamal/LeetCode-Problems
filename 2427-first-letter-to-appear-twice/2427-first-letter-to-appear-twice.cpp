class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>mp;
        for(auto x: s)
            if(mp.count(x)!=0)
                return x;
            else
                mp[x]++;
        return 's';
        
    }
};