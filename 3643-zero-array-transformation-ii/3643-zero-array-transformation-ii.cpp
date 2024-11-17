class Solution {
    int fn(int mid, vector<int>&nums, vector<vector<int>>&queries)
    {
        vector<int> x (nums.size()+1,0);

        for(int i = 0; i<mid; i++)
        {
            x[queries[i][0]]+= queries[i][2];
            x[queries[i][1]+1]-=queries[i][2];
        }
        int prefixsum=0;
        for(int i = 0; i< x.size()-1; i++)
        {
            prefixsum+=x[i];
            if(nums[i]-prefixsum>0)
                return false;
        }return true;

    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int start = 0; int end = queries.size();
        int mid = -1; int pos = -1;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(fn(mid, nums, queries))
            {
                pos= mid;
                end =mid-1;
            }
            else
            {
                start = mid+1;
            }
        }return pos;
        
    }
};