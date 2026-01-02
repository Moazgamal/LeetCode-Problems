public class Solution {
    public int RepeatedNTimes(int[] nums) {

        Dictionary<int,int>mp=new Dictionary<int,int>();
        for(int i = 0; i< nums.Length; i++)
        {
            if(mp.ContainsKey(nums[i]))
                return nums[i];
            mp.Add(nums[i],1);
        }return 0; 
        
    }
}