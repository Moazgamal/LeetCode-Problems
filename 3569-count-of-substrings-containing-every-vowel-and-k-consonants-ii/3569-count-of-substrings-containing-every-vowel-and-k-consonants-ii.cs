public class Solution {
    public long CountOfSubstrings(string word, int k) {
         bool isvowel(char func)
        {
        
        if(func =='a')
                return true;
        if(func =='e')
                return true;
        if(func =='i')
                return true;
        if(func =='o')
                return true;
        if(func =='u')
                return true;
        if(func =='A')
                return true;
        if(func =='E')
                return true;
        if(func =='I')
                return true;
        if(func =='O')
                return true;
        if(func =='U')
                return true;
        else
                return false;
        }
        int[] indices  = new int[word.Length];
        int next1 = word.Length;
        for(int i = word.Length-1; i>=0; i--)
        {
            indices[i] = next1;
            if(!isvowel(word[i]))
                next1 = i;
        }
        int j = 0;
        int cons = 0; 
        Dictionary<char,int> mp = new Dictionary<char,int>();
        long ans = 0;
        for(int i = 0 ; i< word.Length; i++)
        {
            if(isvowel(word[i]))
                {
                    if(mp.ContainsKey(word[i]))
                        mp[word[i]]++;
                    else
                        mp.Add(word[i],1);
                }
            else
                cons++;
            if(cons>k)
            {
                while(j<=i && cons >k)
                {
                    if(isvowel(word[j]))
                    {
                        mp[word[j]]--;
                        if(mp[word[j]] == 0)
                            mp.Remove(word[j]);
                    }
                    else
                        cons--;
                    j++;
                }
                
            }
        while(j<i&&mp.Count() == 5 && cons == k)
            {
                int next = indices[i];
                ans += (next-i);
                if(isvowel(word[j]))
                {
                    if(--mp[word[j]] ==0)
                        mp.Remove(word[j]);
                }
                else
                    cons--;
                j++;
            }
            
        }
        return ans;
        
    }
}