public class Solution {
    public int LongestPalindrome(string[] words) {

        Dictionary<string,int>mp = new Dictionary<string,int>();
        for(int i = 0; i< words.Length; i++)
        {
            if(mp.ContainsKey(words[i]) == true)    
                mp[words[i]]++;
            else
                mp.Add(words[i], 1);
        }
        int evens = 0; 
        int w = 0;
        foreach(KeyValuePair<string, int> kvp in mp)
        {
            string str = kvp.Key;
            char[] u = str.ToCharArray();
            Array.Reverse(u);
            string reversed = new string(u);
            
            if(mp.ContainsKey(reversed) == true && str[0] != str[1])
            {
                int f = mp[reversed];
                f = int.Min(f, kvp.Value);
                evens += (4*f);
                mp[reversed]=0;
            }
            else if(str[0] == str[1])
            {
                int f = kvp.Value;
                if(f%2 ==0)
                    evens += 2*f;
                else
                {
                    evens += (2*(f-1));
                    w = 1;
                }
            }
        }
        return evens+ 2*w;
        
    }
}