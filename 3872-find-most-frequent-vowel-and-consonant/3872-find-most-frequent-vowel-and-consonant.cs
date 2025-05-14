public class Solution {
    public int MaxFreqSum(string s) {
        Dictionary<char,int> mp1 = new Dictionary<char,int>();
        Dictionary<char,int> mp2 = new Dictionary<char,int>();
        int freq1 = 0; int freq2 = 0; 
        
        for(int i = 0; i< s.Length; i++)
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    if(mp1.ContainsKey(s[i]))
                        mp1[s[i]]++; 
                    else
                        mp1[s[i]]= 1;
                    freq1 = int.Max(freq1, mp1[s[i]]);
                }
                else
                {
                    if(mp2.ContainsKey(s[i]))
                        mp2[s[i]]++;
                    else
                        mp2[s[i]] = 1;
                    freq2 = int.Max(freq2, mp2[s[i]]);
                }
            }
        return freq1+ freq2;
        
    }
}