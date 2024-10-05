public class Solution {
    public bool CheckInclusion(string s1, string s2) {

        Dictionary<char,int> mp = new Dictionary<char,int>();
        Dictionary<char,int> mp2 = new Dictionary<char,int>();
        for(int i = 0; i< s1.Count(); i++)
        {
            if(mp.ContainsKey(s1[i]))
            {
                mp[s1[i]]++;
                mp2[s1[i]]++;
            }
            else
                {
                    mp.Add(s1[i],1);
                    mp2.Add(s1[i],1);
                }
        }
        int j = 0;
        for(int i = 0; i< s2.Count() ; i++)
        {
            if(mp.ContainsKey(s2[i]))
            {
                if(mp2.ContainsKey(s2[i])&&mp2[s2[i]]-1 ==0)
                {
                    mp2.Remove(s2[i]);
                    if(mp2.Count() ==0)
                        return true;
                }
                else if(mp2.ContainsKey(s2[i])&&mp2[s2[i]]-1>0)
                {
                    mp2[s2[i]]--;
                    continue;
                }
                else
                {
                    while(j<i && s2[j]!=s2[i])
                    {
                        if(mp2.ContainsKey(s2[j]))
                            ++mp2[s2[j]];
                        else
                            mp2.Add(s2[j],1);
                        j++;
                    }
                    if(mp2.ContainsKey(s2[j]))
                        mp2.Remove(s2[j]);
                    
                    j++;
                }

            }
            else
            {
                while(j<i)
                    {
                        if(mp2.ContainsKey(s2[j]))
                            ++mp2[s2[j]];
                        else
                            mp2.Add(s2[j],1);

                        j++;
                    }
                    j++;
            }
        }
        return false;
        
    }
}