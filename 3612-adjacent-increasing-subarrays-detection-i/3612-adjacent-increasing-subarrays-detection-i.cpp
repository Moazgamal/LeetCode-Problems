class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int l1 =-1;
        for(int i = 0; i< nums.size(); i++)
        {
            int j = i+1;
            for(;  j< nums.size(); j++)
            {
                if(nums[j] > nums[j-1])
                    continue;
                else
                    break;
            }
           
            int l2 = j-i;
            int v = l1!=-1?min(l1,l2):0;
            if(l1==-1)
                l1=j-i;
            v = max(v, l1/2);
            v = max(v, l2/2);
            if(v>=k)
                return true;
            l1=l2;
            i=j-1;
            
            
        }return false;
    }
};