class Solution {
    bool Comp(string &s1 , string &s2, unordered_map<char,int>&mp)
    {
        int i = 0; int j = 0; 
        while(i< s1.size() && j< s2.size())
        {
            if(mp[s1[i]] > mp[s2[j]])
            {
                return true;
            }
            else if(mp[s1[i]] == mp[s2[j]])
            {
                i++; j++;
                continue;
            }
            return false;
        }
        if(j != s2.size())
            return false;
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i = 0; i< order.size(); i++)
        {
            mp[order[i]]= i;
        }
        for(int i = 0; i< words.size()-1; i++)
        {
            if(Comp(words[i+1], words[i],mp))
                continue;
            return false;
        }
        return true;
        
        
    }
};