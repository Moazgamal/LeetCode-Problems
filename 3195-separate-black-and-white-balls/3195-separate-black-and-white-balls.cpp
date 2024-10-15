class Solution {
public:
    long long minimumSteps(string s) {

        int sum = 0;
        char prevchar = s[s.size()-1];
        if(prevchar=='0')
            sum++;
        long long ans = 0;
        for(int i = s.size()-2; i>=0; i--)
        {
            if(s[i] == '1')
            {
                if(prevchar == '0')
                    ans+=(sum);
                
            }
            else
            {
                prevchar='0';
                sum++;
            }
        }return ans;
        
    }
};