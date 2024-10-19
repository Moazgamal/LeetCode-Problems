class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,long long>mp;
        long long ans = LLONG_MIN;
         
        vector<long long>prefixsum(nums.size(),0);
        prefixsum[0]=nums[0];
        for(int i  =1; i< nums.size(); i++)
        {
            prefixsum[i] = prefixsum[i-1]+nums[i];
        }
        for(int i =0; i< nums.size(); i++)
        {
            
            long long no = -k+nums[i];
            long long no2 = k+nums[i];
            
            if(mp.count(no) >0 )
            {
                if(mp[no]==0)
                    ans = max(ans, prefixsum[i]);
                else
                    ans = max(ans, prefixsum[i]-prefixsum[mp[no]-1]);
                
            }
            if(mp.count(no2) >0 )
            {
                if(mp[no2]==0)
                    ans = max(ans, prefixsum[i]);
                else
                    ans = max(ans, prefixsum[i]-prefixsum[mp[no2]-1]);
                
            }
            if(mp.count(nums[i])==0 )
            {
                mp[nums[i]]=i;
            }
            else 
            {
                if(prefixsum[i]-prefixsum[mp[nums[i]]] <=0)
                    mp[nums[i]]=i;
            }

        }
        if(ans==LLONG_MIN)
            return 0;
        return ans;
        
    }
};