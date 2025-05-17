class Solution {
public:
    void sortColors(vector<int>& nums) {

        int cnt1 = 0; int cnt2 = 0; int cnt3= 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == 0)
                cnt1++;
            else if(nums[i] == 1)
                cnt2++;
            else
                cnt3++;
        }int i = 0; 
       
            while(cnt1-- >0)
                nums[i++]= 0;
            while(cnt2-- >0)
                nums[i++] = 1; 
            while(cnt3-->0)
                nums[i++] = 2;
        
    }
};