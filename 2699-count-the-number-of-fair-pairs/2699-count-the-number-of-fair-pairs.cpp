class Solution {
    int binarySearch(int start, int end, int target, vector<int>&nums)
    {
        int mid = -1; int pos = -1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(nums[mid] >= target)
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }return pos;
    }
    int binarySearch2(int start, int end, int target, vector<int>&nums)
    {
        int mid = -1; int pos = -1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(nums[mid] > target)
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }return pos;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long sum = 0; 
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size()-1; i++)
        {
            int lo = binarySearch(i+1, nums.size()-1, lower-nums[i], nums);
            if(lo==-1)
                continue;
            int hi = binarySearch2(i+1, nums.size()-1, upper-nums[i], nums);
            if(hi==-1)
            {
                sum += (nums.size()- lo);
            }
            else
            {
                if(nums[hi] == upper-nums[i])
                {
                    sum += (hi-lo+1);
                }
                else
                    sum += (hi-lo);
            }
            
        }return sum; 
        
    }
};