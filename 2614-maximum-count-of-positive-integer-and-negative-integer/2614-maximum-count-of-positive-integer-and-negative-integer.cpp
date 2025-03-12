class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos1 = -1; 
        int mid = -1; 
        int start = 0; int end = nums.size()-1;
        start = 0; end = nums.size()-1;
        while(start<=end)
        {
            mid = start+(end-start)/2;
            if(nums[mid]==0)
            {
                pos1 = mid;
                end = mid-1; 
            }
            else if(nums[mid] >0)
                end = mid-1;
            else
                start = mid+1;
        }
        mid = -1; 
        int pos2 = -1;
        start = 0; end = nums.size()-1;
        while(start<=end)
        {
            mid= start+(end-start)/2;
            if(nums[mid] <0)
            {
                pos2 = mid;
                end=mid-1;
            }
            else if(nums[mid] >=0)
                end=mid-1; 
        }
        mid=-1;
        int pos3 = -1;
        start = 0; end = nums.size()-1;
        while(start<=end)
        {
            mid = start+(end-start)/2;
            if(nums[mid] >0)
            {
                pos3 = mid;
                end=mid-1;
            }
            else
                start = mid+1;
        }
        if(pos1 ==-1)
        {
            if(pos2==-1 || pos3 ==-1)
                return nums.size(); 
            return max(pos3, (int)nums.size()-pos3);
        }
        if(pos2 ==-1 && pos3 ==-1)
            return 0 ;
        if(pos2 == -1)
        {
            return nums.size()-pos3;
        }
        if(pos3  == -1)
        {
            return pos1;
        }
        return max(pos1, (int)nums.size()-pos3); 
        

        
    }
};