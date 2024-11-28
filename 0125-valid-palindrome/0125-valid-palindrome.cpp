class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        int j = sz-1;
        for(int i =0; j>i ; j--,i++)
        {
            while(i<j && !isalnum(s[i]))
            {
                i++;
            }
            while(i<j && !isalnum(s[j]))
            {
                j--;
            }
            if(i<j && isalnum(s[i]) && isalnum(s[j]))
            {
                if(isdigit(s[i]))
                    if(s[i] != s[j])
                        return false;
                if(tolower(s[i]) != tolower(s[j]))
                    return false;
            }

        }return true;
    }
};