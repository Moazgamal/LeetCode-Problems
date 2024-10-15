public class Solution {
    public long MinimumSteps(string s) {
        int sum = 0;
        long ans = 0;
        for(int i = s.Length-1; i>=0; i--)
        {
            if(s[i] == '1')
            {
                if(sum>0)
                    ans+=(sum);
            }
            else
            {
                sum++;
            }
        }return ans;
        
        
    }
}