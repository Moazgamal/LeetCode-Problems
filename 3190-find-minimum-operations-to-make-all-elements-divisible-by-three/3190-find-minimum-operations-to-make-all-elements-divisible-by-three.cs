public class Solution {
    public int MinimumOperations(int[] nums) {

        int ans = 0; 
        for(int i = 0; i< nums.Length; i++)
        {
            if(nums[i] % 3 == 0)
            {
                continue;
            }
            int x1 = nums[i] /3;
            int c1 = (nums[i]-(x1*3));
            int c2 = ((3*(x1+1))-nums[i]);
            ans += int.Min(c1, c2);
        }return ans; 
        
    }
}