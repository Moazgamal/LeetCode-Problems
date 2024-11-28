class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            totalSum += nums[i];
        }
        int curSum = 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            curSum += nums[i];
            if(curSum-nums[i] == totalSum-curSum)
                return i;
        }
       
        return -1;
    }
};