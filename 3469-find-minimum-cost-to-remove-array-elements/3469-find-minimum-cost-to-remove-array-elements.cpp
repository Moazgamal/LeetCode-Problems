class Solution {
    int fn(int IDX, int carryIDX, vector<int>&nums, vector<vector<int>>&Dp)
    {
        // cout<<carryIDX<<" "<<IDX<<" \n";
        auto &ret = Dp[IDX][carryIDX];
        if(ret != INT_MAX)
            return ret; 
        if(IDX == nums.size())
        {
            return ret = nums[carryIDX];
        }
        if(IDX+1 == nums.size())
        {
            if(carryIDX != nums.size())
                return ret = max(nums[carryIDX], nums[IDX]);
            return ret = nums[IDX];
        }
        if(IDX + 2 == nums.size())
        {
            if(carryIDX == nums.size())
                return ret = max(nums[IDX], nums[IDX+1]);
            return ret = min(nums[IDX], min(nums[IDX+1], nums[carryIDX]))+
                    max(nums[IDX], max(nums[IDX+1], nums[carryIDX]));
        }

        if(carryIDX != nums.size())
        {
            int c1 = max(nums[carryIDX], nums[IDX]) + fn(IDX+2, IDX+1, nums, Dp);
            int c2 = max(nums[carryIDX], nums[IDX+1]) + fn(IDX+2, IDX, nums, Dp);
            int c3 = max(nums[IDX+1], nums[IDX]) + fn(IDX+2, carryIDX, nums, Dp);
            return ret = min(c1, min(c2,c3));
        }
        int c1 = max(nums[IDX+1], nums[IDX]) + fn(IDX+3, IDX+2, nums, Dp);
        int c2 = max(nums[IDX+2], nums[IDX]) + fn(IDX+3, IDX+1, nums, Dp);
        int c3 = max(nums[IDX+1], nums[IDX+2]) + fn(IDX+3, IDX, nums, Dp);
        return ret = min(c1, min(c2,c3));

    }
public:
    int minCost(vector<int>& nums) {
        vector<vector<int>>Dp(nums.size()+1, vector<int>(nums.size()+1, INT_MAX));
        int ans = fn(0, nums.size(), nums, Dp);
        // for(int i = 0; i< Dp.size(); i++)
        // {
        //     for(int j = 0; j< Dp[0].size(); j++)
        //     {
        //         cout<<i<<" IDX "<<j<<" carryIDX "<<Dp[i][j]<<" \n";
        //     }
        // }
        return ans;
    }
};