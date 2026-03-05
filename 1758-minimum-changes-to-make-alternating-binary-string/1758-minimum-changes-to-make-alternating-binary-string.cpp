class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        int first = s[0];
        int ans = INT_MAX;
        for(int i = 1; i< s.size(); i++)
        {
            if(first == s[i])
            {
                cnt++; 
                if(first == '0')
                    first = '1';
                else
                    first = '0';
            }
            else
            {
                first = s[i];
            }
        }
        ans = min(ans, cnt);
        if(s[0] == '1')
        {
            cnt=0;
            first = '0';
            cnt++;
            for(int i = 1; i< s.size(); i++)
            {
                if(first == s[i])
                {
                    cnt++; 
                    if(first == '0')
                        first = '1';
                    else
                        first = '0';
                }
                else
            {
                first = s[i];
            }
            }
            ans = min(ans, cnt);
        }
        else
        {
            cnt=0;
            first = '1';cnt++;
            for(int i = 1; i< s.size(); i++)
            {
                if(first == s[i])
                {
                    cnt++; 
                    if(first == '0')
                        first = '1';
                    else
                        first = '0';
                }
                else
            {
                first = s[i];
            }
            }

            ans = min(ans, cnt);
        }
        return ans; 
    }
};