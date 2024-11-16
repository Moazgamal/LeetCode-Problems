public class Solution {
    public int SmallestNumber(int n, int t) {
        int start = n; int end = 100;
        for(int i = start; i<=end; i++)
        {
            if(fn(i,t))
                return i;
        }
        return 0; 
        bool fn(int val , int t)
    {
        int sum = 1;
        string s = val.ToString();
        for(int i = 0; i< s.Length; i++)
        {
            sum *= (s[i]-'0');
        } 
        if(sum %t ==0)
            return true;
        return false;
    }
        
    }
}