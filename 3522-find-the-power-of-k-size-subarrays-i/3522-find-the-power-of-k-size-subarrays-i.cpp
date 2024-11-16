class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int start = 0; 
        vector<int>result(nums.size()-k+1,-1);
       for(int end = 0; end<nums.size() && start<=nums.size()-k; )
       {
            if(end-start+1 == k)
            {
                result[start]= nums[end];
                start++;
            }
            if(end+1<nums.size() && nums[end]+1== nums[end+1])
            {
                end++;
            }
            else
            {
                while(start<=nums.size()-k&&start<=end)
                {
                    result[start]= -1;
                    start++;
                }
                end++;
            }
       }return result;
        
    }
};