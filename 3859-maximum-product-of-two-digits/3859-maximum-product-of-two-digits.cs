public class Solution {
    public int MaxProduct(int n) {
         int ans = 0; 
        string s = n.ToString();
        for(int i = 0; i< s.Length; i++)
            {
                for(int j = i+1; j< s.Length; j++)
                    {
                        ans = int.Max(ans, (s[i]-'0')*(s[j]-'0'));
                    }
            }
        return ans;
        
    }
}