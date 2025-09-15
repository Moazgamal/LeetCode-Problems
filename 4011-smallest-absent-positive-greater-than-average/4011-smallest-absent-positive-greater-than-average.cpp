class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg =0; double sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++)
        {
            sum+=nums[i];
        }
        avg  = sum/(double)(nums.size());
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] <= 0)
                continue;
            if(nums[i] > avg)
            {
                if(i == 0)
                {
                    if(nums[i] >1)
                        return nums[i]-1;
                }
                else
                {
                    int x = nums[i] ; int y = nums[i-1]>=0 ? nums[i-1]+1:1;
                    while(y < x)
                    {
                        if(y>avg)
                            return y; 
                        y++;
                    }
                }
            }
        }
        return nums[nums.size()-1] > 0 ? nums[nums.size()-1]+1 : 1;  
         
    }
};