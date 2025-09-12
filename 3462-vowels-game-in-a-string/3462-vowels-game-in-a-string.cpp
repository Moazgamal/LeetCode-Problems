class Solution {
    bool isvowel(char c)
    {
        if(c == 'a' || c == 'e' || c== 'i' || c == 'o' || c== 'u')
            return true;
        return false; 
    }
public:
    bool doesAliceWin(string s) {
        int vowels = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(isvowel(s[i]))
            {
                vowels++;
            }
        }
        if(vowels == 0)
            return false; 
        return true; 
        
    }
};