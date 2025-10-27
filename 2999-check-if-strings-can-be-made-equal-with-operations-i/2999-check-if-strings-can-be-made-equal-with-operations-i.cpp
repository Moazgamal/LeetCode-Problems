class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i = 3;
        if((s1[i] != s2[i] && s1[i] != s2[i-2]) ||
        (s1[i-2] != s2[i] && s1[i-2] != s2[i-2]))
            return false;
        i= 2;
        if((s1[i] != s2[i] && s1[i] != s2[i-2]) ||
        (s1[i-2] != s2[i] && s1[i-2] != s2[i-2]))
            return false;
        return true; 

        
    }
};