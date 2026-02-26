class Solution {
    void fn(string &str, int &ans)
    {
        if(str.size() == 2)
            return ; 
        string m(str.size()-1, '0');
        if(m == str.substr(0, str.size()-1))
            return; 
        for(int i = str.size()-1; i>=0; i--)
        {
            if(str[i] == '1')
                str[i] = '0';
            else
            {
                str[i] = '1';
                ans++;
                break;
            }
        }
    }
    void fn2(string &str, int &ans)
    {
        int i = str.size()-1;
        for(; i>=0; i--)
        {
            if(str[i] == '1')
                break;
        }
        ans += (str.size()-i-1);
        string s = str.substr(0, i+1);
        str = "0"+s;
    }
public:
    int numSteps(string s) {
        int ans = 0;
        s = "0"+s;
        while(true)
        {
            if(s[s.size()-1] == '1')
            {
                int j = ans; 
                fn(s,ans);
                if(j == ans)
                    return ans;
            }
            else
                fn2(s, ans);
        }
        return ans; 
    }
};