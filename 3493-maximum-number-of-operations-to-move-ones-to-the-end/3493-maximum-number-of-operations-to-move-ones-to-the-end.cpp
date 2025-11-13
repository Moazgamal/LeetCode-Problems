class Solution {
public:
    int maxOperations(string s) {
        int prevOnes = 0; int ans = 0; 
        for(int i = 0; i< s.size(); )
        {
            if(s[i] == '0')
            {
                while(i< s.size() && s[i] == '0')
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