public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int[] result = new int[nums.Length];
        for(int i = 0; i< nums.Length; i++)
            result[i] = 1; 
        int acc = 1; 
        for(int i = 0; i< nums.Length-1; i++)
        {
            result[i+1] = acc*nums[i];
            acc*=nums[i];
        }
        acc =1 ; 
        for(int i = nums.Length-1; i >= 1; i--)
        {
            result[i-1] *= (acc*nums[i]);
            acc*=nums[i];
        }
        return result;
        
    }
}