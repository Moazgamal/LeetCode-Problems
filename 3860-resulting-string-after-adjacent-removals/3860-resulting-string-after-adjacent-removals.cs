public class Solution {
    public string ResultingString(string s) {

        Stack<char> st = new Stack<char>();
        for(int i = 0; i< s.Length; i++)
        {
            if(st.Count==0)
            {
                st.Push(s[i]); continue;
            }
            else if(Math.Abs((st.Peek()-'0')-(s[i]-'0')) == 1 || s[i] == 'a' && st.Peek()=='z' || s[i] == 'z' && st.Peek()=='a')
            {
                st.Pop();
            }
            else
            {
                st.Push(s[i]);
            }
        }
        StringBuilder ans  = new StringBuilder(); 
        while(st.Count>0)
        {
            ans.Append(st.Peek()); st.Pop();
        }
        char[] x = ans.ToString().ToCharArray();
        Array.Reverse(x);
       
        return new string(x);
        // reverse(ans.begin(), ans.end());return ans; 
        
    }
}