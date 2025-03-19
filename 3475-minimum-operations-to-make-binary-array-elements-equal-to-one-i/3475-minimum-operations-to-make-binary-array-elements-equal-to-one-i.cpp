class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0; 
        int ans = 0; 
        while(i+2< nums.size())
        {
            if(nums[i]==0)
            {
                nums[i]=1; nums[i+1]=!nums[i+1]; nums[i+2]= !nums[i+2];
                ans++;
            }
            i++;
        }
        if(nums[nums.size()-2]==0 || nums[nums.size()-1]==0)
            return -1;
        return ans; 
    }
};