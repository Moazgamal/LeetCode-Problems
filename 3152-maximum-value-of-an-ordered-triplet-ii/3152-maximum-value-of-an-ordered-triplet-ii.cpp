class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0; 
        vector<int> maxis(nums.size(),-1);
        vector<int> minis(nums.size(),-1);
        
        int maxi = nums.size()-1;
        int mini = 0;
        for(int i = nums.size()-2; i>=0 ; i--)
        {
            maxis[i] = maxi;
            if(nums[i] > nums[maxi])
                maxi = i ;
        }
        for(int i = 1; i< nums.size()-1; i++)
        {
            minis[i] = mini;
            if(nums[i]> nums[mini])
                mini = i; 
        }
        for(int i = 1; i< nums.size(); i++)
        {
            int n1 = maxis[i];
            int n2 = minis[i];
            if(n1 == -1 || n2 == -1)
                continue;
            ans = max(ans , (long long)(nums[n2]-nums[i])*nums[n1]);
        }
        
        
        return ans; 


    }
};