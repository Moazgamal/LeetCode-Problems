public class Solution {
    public long MaximumTotalSum(int[] maximumHeight) {

        long ans = 0; 

        Array.Sort(maximumHeight);
         ans=maximumHeight[maximumHeight.Length-1];
        int x=maximumHeight[maximumHeight.Length-1];

        for(int i = maximumHeight.Length-2; i>=0; i--)
        {
            
            if(maximumHeight[i] >= x)
            {
                if(x-1 ==0)
                    return -1;
                ans+=(x-1);
                x=x-1;
            }
            else
            {
                ans+=maximumHeight[i];
                x=maximumHeight[i];
                
            }
            
        }
        
        return ans;

        
    }
}