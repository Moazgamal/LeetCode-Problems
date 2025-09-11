class Solution {
    bool isvowel(char c)
    {
        if(c == 'a' || c == 'A' || c == 'e' || c== 'E' || c== 'i' || c== 'I'
        || c == 'o' || c== 'O' || c== 'u' || c== 'U')
            return true; 
        return false; 
    }
public:
    string sortVowels(string s) {

        vector<char>v;
        for(int i = 0; i< s.size(); i++)
        {
            if(isvowel(s[i]))
            {
                v.push_back(s[i]);
            }
        }
        int j = 0; 
        sort(v.begin(), v.end());
        for(int i = 0; i< s.size(); i++)
        {
            if(isvowel(s[i]))
            {
                s[i] = v[j++];
            }
        }
        return s; 
        
    }
};