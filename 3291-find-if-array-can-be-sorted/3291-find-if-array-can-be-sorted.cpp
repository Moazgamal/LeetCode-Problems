class Solution {
    int br(int num)
    {
        int cnt = 0; 
        while(num)
        {
            cnt += (num%2);
            num= num/2;
        }return cnt;
    }

public:
    bool canSortArray(vector<int>& nums) {
        
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = 0; j< nums.size()-i-1; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    if(br(nums[j]) != br(nums[j+1]))
                        return false;
                    else
                        swap(nums[j], nums[j+1]);
                }
            }
        }return true;
        
    }
};