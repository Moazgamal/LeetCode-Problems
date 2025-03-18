public class Solution {
    public int LongestNiceSubarray(int[] nums) {
        int acc = nums[0] ; 
        int ans = 1; 
        int j = 0; 

        for(int i =1; i< nums.Length; i++)
        {
            while((acc & nums[i])!=0 )
            {
                acc = acc ^ nums[j];
                j++;
            }
            acc = acc | nums[i];
            ans = int.Max(ans, i-j+1);
        }return ans;
    }
}