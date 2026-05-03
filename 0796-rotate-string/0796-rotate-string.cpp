class Solution {
public:
    bool rotateString(string s, string goal) {
        int sz  = s.size();
        if(s == goal)
            return true; 
        for(int i = 0; i< sz; i++)
        {
            char c = s[i];
            s.push_back(c);
            if(s.substr(i+1, sz) == goal)
                return true; 
        }
        return false;
    }
};