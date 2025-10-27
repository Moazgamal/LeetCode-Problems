class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long score = 0; 
        for(int i =0; i< nums.size(); i++)
                nums[i] = abs(nums[i]); 
        
        sort(nums.begin(), nums.end());
        int i = 0; int j = nums.size()-1;
        while(i<j)
            {
                score += (nums[j]*nums[j]-nums[i]*nums[i]);
                i++;j--;
            }
        if(i == j)
            score += (nums[i]*nums[i]);
    return score; 
        
    }
};