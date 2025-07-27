class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int ans = 0; int i = 1;  int sz = ((int)nums.size())-1;
        while(i<sz)
        {
            int j = i-1; int k = i+1;
            while(k< (int)nums.size() && nums[k] == nums[i])
            {
                k++;
            }
            if(k< sz+1)
            {
                if(nums[j]<nums[i] && nums[k]<nums[i])
                {
                    ans++; 
                }
                else if(nums[j] > nums[i] && nums[k]>nums[i])
                {
                    ans++; 
                }
            }
            i=k;
        }
        return ans;
        
    }
};