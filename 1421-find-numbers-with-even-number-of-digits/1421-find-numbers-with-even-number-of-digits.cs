public class Solution {
    public int FindNumbers(int[] nums) {
        int ans = 0; 
        for(int i = 0; i< nums.Length; i++)
        {
            int cnt = 0; 
            while(nums[i] > 0)
            {
                nums[i]/=10;cnt++;
            }
            if(cnt %2 ==0)
                ans++;
        }return ans;
    }
}