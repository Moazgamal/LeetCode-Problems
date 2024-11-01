class Solution {
public:
    string makeFancyString(string s) {
        string x ="";
        for(int i = 0; i< s.size(); i++)
        {
            
            if(i-2>=0 && s[i] == s[i-1] && s[i] == s[i-2])
                continue;
            x += s[i];
        }return x;
        
    }
};