class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>mp;
        for(int i = 0; i< brokenLetters.size(); i++)
        {
            mp[brokenLetters[i]]++;
        }
        int i = 0;  int ans = 0; 
        while(i<text.size())
        {
            bool s = true;
            while(i< text.size() && text[i] != ' ')
            {
                if(mp.count(text[i]) != 0)
                    s = false; 
                i++;
            }
            if(s)
                ans++;
            i++;
        }
        return ans; 
        
    }
};