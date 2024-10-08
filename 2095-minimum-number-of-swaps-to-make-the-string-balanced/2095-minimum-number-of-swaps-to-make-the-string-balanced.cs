public class Solution {
    public int MinSwaps(string s) {
        int m = s.Count();
        int  j = m-1;
        int swaps= 0;
        int prevno=0;
        for(int i = 0; i< m; i++)
        {
            if(s[i]==']')
            {
                if(prevno==0)
                {
                    while(s[j]!='[')
                    {
                        j--;
                    }
                    j--;
                    prevno++;
                    swaps++;
                }
                else
                    prevno--;
            }
            else
            {
                if(i<=j)
                    prevno++;
                else
                    break;
            }
        }
        return swaps;

        
    }
}