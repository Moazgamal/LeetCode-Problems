class Solution {
    void getAllCombins(int start, int end, vector<int>&subsets, int sum, vector<int>&nums)
    {
        // pick
        if(start > end)
        {
            subsets.push_back(sum); return;
        }
        getAllCombins(start+1, end, subsets, sum+nums[start], nums);
        getAllCombins(start+1, end, subsets, sum, nums);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>subsets1;
        vector<int>subsets2;
        int end1 = 0; 
        int start2 = 0; 
        int res = INT_MAX;
        if(nums.size()%2 == 0)
        {
            end1 = nums.size()/2-1;
            start2 = nums.size()/2;
        }
        else
        {
            end1 = nums.size()/2;
            start2 = nums.size()/2+1;
        }

        getAllCombins(0, end1, subsets1, 0, nums);
        getAllCombins(start2, nums.size()-1, subsets2, 0, nums);
        sort(subsets2.begin(), subsets2.end());
        for(int i =0; i< subsets1.size(); i++)
        {
            int sum1 = subsets1[i];
            int sum2 = goal-sum1;
            auto itr = lower_bound(subsets2.begin(), subsets2.end(), sum2);

            if(itr!=subsets2.end())
                res = min(res, abs((sum1+(*itr))-goal));
            if(itr!= subsets2.begin())
            {
                auto it = itr; --it;
                res = min(res, abs((sum1+(*it))-goal));
            }      
        }
        return res;
    }
};