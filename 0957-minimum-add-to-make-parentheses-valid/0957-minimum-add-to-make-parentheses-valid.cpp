class Solution {
public:
    int minAddToMakeValid(string s) {
        int prevno=0;
        int ans =0;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i]== '(')
            {
                prevno++;
            }
            else
            {
                if(prevno==0)
                {
                    ans++;
                }
                else
                    prevno--;
            }
        }
        return ans+prevno;
        
    }
};