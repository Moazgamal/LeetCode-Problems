class Solution {
public:
    bool hasSameDigits(string s) {
        string str = "";
        while(true)
            {
                for(int i = 0; i< s.size()-1; i++)
                    {
                        int x = ((s[i]-'0') + (s[i+1]-'0'))%10;
                        str.push_back(x+'0');
                    }
                if(str.size()==2)
                {
                    if(str[0] == str[1])
                        return true;
                    return false;
                }
                if(str.size()<2)
                    return false;
                s = str;
                str.clear();
                continue;
            }
        return false;
    }
};