class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        int i = 0; 
        int sz = s.size();
        while(i < sz)
        {
            int j = i;
            bool m = false;
            while(j < sz && s[j] == '1' && s[j] == s[i])
            {
                m = true;
                j++;
            }
            if(m)
            {
                if(cnt >0)
                    return false;
                cnt++;
            }
            i=j+1;
        }
        return cnt ==1 ? true : false;
    }
};