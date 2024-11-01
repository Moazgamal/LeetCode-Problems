public class Solution {
    public string MakeFancyString(string s) {

        StringBuilder x = new StringBuilder();
        int j =0; int sz = s.Count();
        
        for(int i = 0; i< sz; i++)
        {
            if(j-2>=0 && s[i] == x[j-1] && s[i] == x[j-2])
                continue;
            x.Append(s[i]); j++;
        }return x.ToString();
        
    }
}