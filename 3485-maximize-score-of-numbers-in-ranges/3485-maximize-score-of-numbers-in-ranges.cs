public class Solution {
    public int MaxPossibleScore(int[] start, int d) {
        bool fn(long mid, ref int[]start, int d)
    {
        long  prev=start[0];
        for(int i=1 ; i<start.Length; i++){
            long next=long.Max(prev+mid, (long)(start[i]));
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }
    Array.Sort(start);

        long i = 0;
        int sz = start.Length;
        long j = start[sz-1] - start[0] + d;
        int ans = -1;
        long mid = -1;
        while(i<=j)
        {
             mid = i+(j-i)/2;
            if(fn(mid, ref start, d))
            {
                ans = (int)mid;
                i = mid+1;
            }
            else
            {
                j= mid-1;
            }
        }
        return ans;
        
    }
}