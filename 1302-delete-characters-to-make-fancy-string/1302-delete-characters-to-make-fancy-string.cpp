class Solution {
public:
    string makeFancyString(string s) {
        int i = 0; 
        string str ="";
        while(i<s.size())
        {
            int j = i+1;
            while(j<s.size() && s[i] == s[j])
            {
                j++;
            }
            if(j-i>=3)
            {
                str.push_back(s[i]);
                str.push_back(s[i]);
                i=j;
            }
            else
            {
                str.push_back(s[i]);
                i++;
            }
        }return str; 
        
    }
};