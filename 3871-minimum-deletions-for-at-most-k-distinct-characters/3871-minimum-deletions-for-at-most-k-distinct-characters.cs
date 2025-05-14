public class Solution {
    public int MinDeletion(string s, int k) {

        Dictionary<char,int>mp = new Dictionary<char,int>();
        for(int i = 0; i< s.Length; i++)
            {
                if(mp.ContainsKey(s[i]))
                    mp[s[i]]++;
                else
                    mp[s[i]]= 1;
            }
        if(mp.Count <=k)
            return 0; 
        int sz = mp.Count;
        List<int>v = new List<int>();
        foreach( var x in  mp)
            {
                v.Add(x.Value);
            }
        v.Sort();
        int ops = 0; 
        int sz2 = v.Count;
        for(int i = 0; i< sz2; i++)
            {
                ops += v[i];
                sz--;
                if(sz ==k)
                    return ops;
            }
        return ops;
        
    }
}