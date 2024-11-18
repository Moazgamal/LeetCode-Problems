public class Solution {
    public int[] Decrypt(int[] code, int k) {

        int[]res = new int[code.Length];
        
        if(k>0)
        {
            int i = 1; int j = k;
            int sum = 0;
            int t = 1;
            while(t<=j)
            {
                sum+=code[t];t++;
            }
            int idx = 0; 
            res[idx]=sum;
            idx++;
            t = i;
            while(idx<code.Length)
            {
                sum-=code[t];
                t++; j++; 
                if(t>=code.Length)
                    t=0;
                if(j>=code.Length)
                    j=0;
                sum+=code[j];
                res[idx++] = sum;
            }

        }
        if(k<0)
        {
            int i = code.Length-2; int j = code.Length-2-(-k)+1;
            int sum = 0;
            int t = i;
            while(t>=j)
            {
                sum+=code[t];t--;
            }
            int idx = code.Length-1; 
            res[idx]=sum;
            idx--;
            t = i;
            while(idx>=0)
            {
                sum-=code[t];
                t--; j--; 
                if(t<0)
                    t=code.Length-1;
                if(j<0)
                    j=code.Length-1;
               
                sum+=code[j];
                res[idx--] = sum;
            }

        }
        return res;
        
    }
}