public class Solution {
    public int MaxAdjacentDistance(int[] nums) {
        int ans = Math.Abs(nums[0]-nums[1]);
        for(int i = 1; i< nums.Length-1; i++)
            {
                ans = int.Max(ans,Math.Abs(nums[i]-nums[i+1]));
            }
        ans = int.Max(ans, Math.Abs(nums[nums.Length-1]-nums[0]));
        return ans;
        
    }
}