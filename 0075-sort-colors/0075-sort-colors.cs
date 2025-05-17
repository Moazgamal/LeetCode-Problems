public class Solution {
    public void SortColors(int[] nums) {

        int cnt1 = 0; int cnt2 = 0; int cnt3= 0; 
        for(int i = 0; i< nums.Length; i++)
        {
            if(nums[i] == 0)
                cnt1++;
            else if(nums[i] == 1)
                cnt2++;
            else
                cnt3++;
        }int j = 0; 
       
            while(cnt1-- >0)
                nums[j++]= 0;
            while(cnt2-- >0)
                nums[j++] = 1; 
            while(cnt3-->0)
                nums[j++] = 2;
        
    }
}