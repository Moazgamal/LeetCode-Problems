public class Solution {
    public long MinSum(int[] nums1, int[] nums2) {

        long  ans = 0; 
        long  mini1 = 0; 
        long  maxi1 = mini1;
        long  mini2 = 0; 
        long  maxi2 = mini2;
        for(int i = 0; i< nums1.Length; i++)
        {
            if(nums1[i] == 0)
            {
                mini1 += 1;
                maxi1 = long.MaxValue;
            }
            else
                mini1 += nums1[i];
        }
        for(int i = 0; i< nums2.Length; i++)
        {
            if(nums2[i] == 0)
            {
                mini2 += 1;
                maxi2 = long.MaxValue;
            }
            else
                mini2 += nums2[i];
        }
        if(maxi1 != long.MaxValue)
            maxi1 = mini1;
        if(maxi2 != long.MaxValue)
            maxi2 = mini2;
        if(mini1 > maxi2 || mini2 > maxi1)
            return -1;
        return Math.Max(mini1, mini2);

        
    }
}