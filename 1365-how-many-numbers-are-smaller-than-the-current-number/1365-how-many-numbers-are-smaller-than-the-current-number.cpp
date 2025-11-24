class Solution {
    int BS(int target, vector<int>&v)
    {
        int start = 0; int end = v.size()-1;
        int mid = -1; int pos = -1; 
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(v[mid] >= target)
            {
                end = mid-1;
            }
            else
            {
                pos = mid;
                start = mid+1;
            }
        }
        return pos; 
    } 
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v=nums;
        vector<int>ans(nums.size());
        sort(v.begin(), v.end());
        for(int i = 0; i< nums.size(); i++)
        {
            int x = BS(nums[i], v);
            if(x == -1)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = x+1;
            }
        }return ans; 
        
    }
};