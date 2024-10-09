public class Solution {
    public int MinAddToMakeValid(string s) {

        int prevno=0;
        int ans =0;
        int m = s.Length;
        for(int i = 0; i< m; i++)
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
}