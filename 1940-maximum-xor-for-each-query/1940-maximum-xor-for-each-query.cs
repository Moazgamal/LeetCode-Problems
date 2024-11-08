public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {

        int x = (1<<maximumBit)-1;
        int[]result = new int[nums.Length];
        result[0] = nums[0]^x;
        for(int i=1; i< nums.Length; i++)
        {
            nums[i] = nums[i-1]^nums[i];
            result[i] = nums[i]^x;
        }
        Array.Reverse(result);
        return result;
        
    }
}