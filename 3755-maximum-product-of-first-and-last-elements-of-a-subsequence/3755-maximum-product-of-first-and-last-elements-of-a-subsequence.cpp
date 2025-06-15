class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = LONG_MIN; 
        int mini = INT_MAX;
        int maxi = INT_MIN;
        if(m==1)
        {
            if(nums.size() == 1)
                return (long long)nums[0]*nums[0];
            for(int i = 0; i< nums.size(); i++)
                {
                    long long val = abs(nums[i]);
                    ans = max(ans, val);
                }
            return ans*ans ;
        }
        mini = nums[0];
        maxi = nums[0];
        int j = 0; 
        for(int i = 1; i< nums.size();i++)
            {
                if((i-m)+1 >=0)
                {
                    mini = min(mini, nums[j]);
                    maxi = max(maxi, nums[j]);
                    j++;
                    if(nums[i]==0)
                    {
                        long long val = 0; 
                        ans = max(ans, val);
                    }
                    else if(nums[i]<0)
                    {
                        long long val = (long long)nums[i]*mini;
                        ans = max(ans, val);
                    }
                    else
                    {
                        long long val = (long long)nums[i] * maxi;
                        ans = max(ans, val);
                    }
                }
                
               
            }
        return ans; 
        
    }
};