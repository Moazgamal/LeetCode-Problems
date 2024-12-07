class Solution {
    bool isPossible(int mid, vector<int>&nums, int op)
    {
        int totalop = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            int ope = (ceil(nums[i]/(double)mid))-1;
            totalop += ope;
            if(totalop > op)
                return false;
        }return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        

        int start = 1; 
        int end = INT_MIN;
        for(int i = 0; i< nums.size(); i++)
        {
            end = max(nums[i] , end);
        }
        int pos = -1; int mid = -1; 
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(isPossible(mid, nums, maxOperations))
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return pos;
    }
};