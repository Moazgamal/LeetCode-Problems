class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0; 
        for(long long i = 0; i< nums.size(); i++)
        {
            sum+= nums[i];
        }
        long long f = sum%p;
        

        if(f==0)
            return 0;
        long long ans = INT_MAX;
        long long prefix = 0;
        unordered_map<long long,long long> mp;
        for(long long i = 0; i< nums.size(); i++)
        {
            prefix+=nums[i];
            prefix%=p;
            if(prefix==f)
            {
                ans = min(ans, i+1);
            }
            long long no= (prefix -f+p)%p;
            if(mp.count(no)>0)
            {
                ans= min(ans, i-mp[no]);
            }
            mp[prefix] = i ;
        }
        if(ans >= INT_MAX || ans == nums.size())
            return -1;
        return ans;
        
    }
};