class Solution {
    bool isp(int start, int end, string &x)
    {
        if(start> end)
            return true; 
        if(start == end)
            return true; 
        if(x[start] == x[end])
            return isp(start+1, end-1, x);
        return false; 
    }
    int fn(string x, string &t)
    {

        int o = 0;
        if(isp(0, x.size()-1, x))
            {
                o= max(o, (int)x.size());
            }
        string m = x; 
        for(int i =0; i< t.size(); i++)
        {
            m = x; m.push_back(t[i]);
            for(int j =i; j< t.size(); j++)
            {
                if(i==j)
                {
                    if(isp(0, m.size()-1, m))
                        {
                            o= max(o, (int)m.size());
                        }
                    continue;
                }
                m.push_back(t[j]);
                if(isp(0, m.size()-1, m))
                    {
                        o= max(o, (int)m.size());
                    }
            }
        }
        return o;
    }
public:
    int longestPalindrome(string s, string t) {
int ans = 1; 
        for(int i = 0; i< s.size(); i++)
        {
            string x = ""; x.push_back(s[i]);
            for(int j = i; j< s.size(); j++)
            {
                if(j==i)
                {
                    ans = max(ans, fn(x,t));
                    continue;
                }
                x.push_back(s[j]);
                ans = max(ans, fn(x,t));

            }
        }
        for(int i = 0; i< t.size(); i++)
        {
            string x = ""; x.push_back(t[i]);
            for(int j = i; j< t.size(); j++)
            {
                if(j==i)
                {
                    if(isp(0,x.size()-1, x))
                        ans = max(ans, (int)x.size());
                    continue;
                }
                x.push_back(t[j]);
                if(isp(0,x.size()-1, x))
                    ans = max(ans, (int)x.size());

            }
        }
        return ans;
        
    }
};