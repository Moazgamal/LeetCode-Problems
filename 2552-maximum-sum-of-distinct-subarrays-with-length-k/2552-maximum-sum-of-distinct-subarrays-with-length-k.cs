public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {

        long  ans = 0;
        int j = 0;
        long  sum = 0;  
        Dictionary<int,int>mp = new Dictionary<int,int>();
        for(int i = 0; i< nums.Length; i++)
        {
            sum+=nums[i];
            if(mp.ContainsKey(nums[i]))
            {
                int old =j;
                j = mp[nums[i]]+1;
                while(old<j)
                {
                    mp.Remove(nums[old]);
                    sum-=nums[old];
                    old++;
                }
                mp[nums[i]]=i;
            }
            else
                mp.Add(nums[i],i);
            if(i-j+1==k)
            {
                ans= long.Max(ans, sum);
                sum-=nums[j];
                mp.Remove(nums[j]);
                j++;
            }
        }return ans;
        
    }
}