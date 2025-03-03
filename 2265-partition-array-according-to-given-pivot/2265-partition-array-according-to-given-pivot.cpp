class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ids ;
        vector<int> ids2 ;
        vector<int> ids3 ;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] <pivot)
            {
                ids.push_back(i);
            }
            else if(nums[i] == pivot)
            {
                ids2.push_back(i);
            }
            else
            {
                ids3.push_back(i);
            }
        }
        sort(ids.begin(), ids.end());
        sort(ids2.begin(), ids2.end());
        vector<int> res;
        for(int i = 0; i< ids.size(); i++)
        {
            res.push_back(nums[ids[i]]);
        }
        for(int i = 0; i< ids2.size(); i++)
        {
            res.push_back(nums[ids2[i]]);
        }
        for(int i = 0; i< ids3.size(); i++)
        {
            res.push_back(nums[ids3[i]]);
        }return res;

    }
};