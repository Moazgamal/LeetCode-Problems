class Solution {
    int fn(int target, vector<int> &nums)
    {
        int start = 1; int end = nums.size()-1;
        int pos = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] > target)
                start = mid+1;
            else
            {
                pos  = mid;
                end = mid-1;
            }
        }
        return pos;
    }
    int search(int start, int end, int target, vector<int>&nums)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return -1; 
    }
public:
    int search(vector<int>& nums, int target) {

        int idx = fn(nums[0], nums);
        if(idx == -1)
            return search(0, nums.size()-1, target, nums);
        else
        {
            int idx1 = search(0, idx-1, target, nums);
            if(idx1 != -1)
                return idx1;
            int idx2 = search(idx, nums.size()-1, target, nums);
            return idx2;
        }
        return -1;
    }
};