class Solution {
    bool fn(int idx, string &str, unordered_map<string, bool>&mp)
    {
        if(idx > str.size())
        {
            if(mp.count(str) == 0)
                return false;
            return true;
        }
        str[idx] = '0';
        bool firstChoice = fn(idx+1, str, mp);
        if(firstChoice == false)
            return false;
        str[idx] = '1';
        bool secondChoice = fn(idx+1, str, mp);
        return secondChoice;
    }
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        unordered_map<string,bool>mp;
        for(int i = 0; i <= s.size()-k; i++)
            mp[s.substr(i,k)]=true;

        string str(k, '0');
        return fn(0,str,mp);
    }
};