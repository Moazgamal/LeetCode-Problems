class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0; int sz = (int)s.size();
        for(int i = 0; i< sz; i++)
            if(s[i] == 'a' || s[i] == 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u')
                vowels++;

        if(vowels == 0)
            return false; 
        return true; 
        
    }
};