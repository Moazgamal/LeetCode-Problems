class Solution {
    bool fn(int idx, vector<int>nums, int dir)
    {
        int cnt = 0; 
        while(idx < nums.size() && idx >=0)
        {
            if(nums[idx] == 0)
            {
                cnt++;
                idx += dir;
            }
            else if(nums[idx] > 0)
            {
                nums[idx] -= 1;
                dir = (-1*dir);
                idx += dir;
            }
        }
        bool x = true;
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                x= false; break;
            }
        }
        return x; 
    }
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(fn(i, nums, 1))
                    ans++;
                if(fn(i, nums, -1))
                    ans++;
            }
        }return ans; 
        
    }
};