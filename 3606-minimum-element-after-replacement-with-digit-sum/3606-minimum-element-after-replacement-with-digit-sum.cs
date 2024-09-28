public class Solution {
    public int MinElement(int[] nums) {
         int ans = int.MaxValue;

        for(int i =0; i< nums.Length; i++)
        {
            string s  = nums[i].ToString();
            int acc=0;
            for(int j=0; j< s.Length; j++)
            {
                acc+= (s[j]-'0');
            }
            ans=int.Min(ans,acc);
        }return ans;
        
    }
}