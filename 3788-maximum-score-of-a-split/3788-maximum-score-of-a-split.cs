public class Solution {
    public long MaximumScore(int[] nums) {

         long ans = int.MinValue;
         long coll = 0; 
        // multiset<int>mt;
        int[] suffix = new int[nums.Length];
        for(int i = 0; i< suffix.Length; i++)
        {
            suffix[i] = int.MaxValue;
        }
        // Array.Fill(suffix, int.MaxValue);
        suffix[suffix.Length-1]= nums[nums.Length-1];
        for(int i = nums.Length-2; i>=0; i--)
        {
            suffix[i] = Math.Min(nums[i], suffix[i+1]);
        }
        for(int i = 0; i< nums.Length-1; i++)
        {
            // mt.erase(mt.find(nums[i]));
            coll += nums[i];
            ans = Math.Max(ans, coll-suffix[i+1]);
        }return ans; 
        
    }
}