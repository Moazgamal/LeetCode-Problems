class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0; 
        vector<long long> maxis(nums.size(),-1);
        vector<long long> minis(nums.size(),-1);
        
        long long maxi = nums.size()-1;
        long long mini = 0;
        for(int i = nums.size()-2; i>=0 ; i--)
        {
            maxis[i] = maxi;
            if(nums[i] > nums[maxi])
                maxi = i ;
        }
        for(int i = 1; i< nums.size(); i++)
        {
            minis[i] = mini;
            if(nums[i]> nums[mini])
                mini = i; 
        }
        for(int i = 1; i< nums.size(); i++)
        {
            long long n1 = maxis[i];
            long long n2 = minis[i];
            if(n1 == -1 || n2 == -1)
                continue;
            ans = max(ans , (long long)(nums[n2]-nums[i])*nums[n1]);
        }
        for(int i = 0; i<=0; i++)
        {
            for(int j  = i+1; j< nums.size()-1; j++)
            {
                int idx = maxis[j];
                if(idx ==-1)
                    continue;
                ans = max(ans, (long long)(nums[0]-nums[j])*nums[idx]);
            }
        }
        
        return ans; 


    }
};