class Solution {
    int fn(int target, vector<int> &nums, int m)
    {
        int start = m; int end = nums.size()-1;
        int pos = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] >= target)
                start = mid+1;
            else
            {
                pos  = mid;
                end = mid-1;
            }
        }
        return pos;
    }
    int search2(int start, int end, int target, vector<int>&nums)
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
    bool search(vector<int>& nums, int target) {

        int m = 0;

        while(m< nums.size() && nums[0] == nums[m])
            m++;
        
        if(nums[0] == target)
            return true;

        if(m == nums.size())
            return false;


        int idx = fn(nums[m], nums, m);
        cout<<idx<<" 1\n";
        if(idx == -1)
        {
            if(search2(m, nums.size()-1, target, nums) != -1)
                return true;
        }
        else
        {
            int idx1 = search2(m, idx-1, target, nums);
            cout<<idx1<<" 2\n";
            if(idx1 != -1)
                return true;
            int idx2 = search2(idx, nums.size()-1, target, nums);
            cout<<idx2<<" 3\n";
            if(idx2 != -1)
                return true;
        }
        return false;
        
    }
};