public class Solution {
    public int MaxWidthRamp(int[] nums) {

        int ans= 0;
        int curr = 0;
        int sz = nums.Length;
        List<int> minis = new List<int>(); minis.Add(0);
        for(int i  =1; i< sz; i++)
        {
            
            int j  = minis.Count-1;
            if(nums[i] < nums[minis[j]])
            {
                minis.Add(i);
                continue;
            }
            while(j>=0&&nums[i] >= nums[minis[j]])
            {
                ans = int.Max(ans, i-minis[j]);
                j--;
            }
            
        }return ans;

        
    }
}