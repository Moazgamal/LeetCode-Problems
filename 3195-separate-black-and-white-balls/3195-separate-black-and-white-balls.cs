public class Solution {
    public long MinimumSteps(string s) {
        int sum = 0;
        char prevchar = s[s.Length-1];
        if(prevchar=='0')
            sum++;
        long ans = 0;
        for(int i = s.Length-2; i>=0; i--)
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
}