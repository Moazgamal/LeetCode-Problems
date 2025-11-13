class Solution {
public:
    int maxOperations(string s) {
        int prevOnes = 0; int ans = 0; int i = 0; int sz = (int)s.size();
        while(i < sz)
        {
            if(s[i] == '0')
            {
                while(i< sz && s[i] == '0')
                {
                    i++;
                }
                ans += prevOnes;
            }
            else
            {
                prevOnes++; i++;
            }
        }return ans; 
        
    }
};