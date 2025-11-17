class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0; 
        int sz = (int)nums.size(); 
        while(i < sz)
        {
            if(nums[i] == 1)
            {
                int j = i+1;
                while(j< sz && nums[j] == 0)
                {
                    j++;
                }
                if(j< sz && j-i-1 <k)
                    return false; 
                i=j;
            }
            else
                i++;
        }return true; 
    }
};