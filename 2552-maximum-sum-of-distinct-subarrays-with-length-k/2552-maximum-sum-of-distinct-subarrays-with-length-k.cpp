class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int j = 0;
        long long sum = 0;  
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            sum+=nums[i];
            if(mp.count(nums[i]) >0)
            {
                int old =j;
                j = mp[nums[i]]+1;
                while(old<j)
                {
                    mp.erase(nums[old]);
                    sum-=nums[old];
                    old++;
                }
                mp[nums[i]]=i;
            }
            else
                mp[nums[i]] = i;
            if(i-j+1==k)
            {
                ans= max(ans, sum);
                sum-=nums[j];
                mp.erase(nums[j]);
                j++;
            }
        }return ans;
        
    }
};