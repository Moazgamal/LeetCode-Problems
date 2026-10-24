class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        // vector<int>j = nums;
        // sort(j.begin(), j.end());
        vector<int>x;
       
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] != i)
                x.push_back(nums[i]);
        }
        if(x.size() == 0)
            return 0; 
        int m = x[0];
        for(int i=0; i< x.size(); i++)
        {
            m = m & x[i];
        }
        return m ; 
        
    }
};