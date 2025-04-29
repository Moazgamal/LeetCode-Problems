class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0; 
        int maxi = 0; 
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
            maxi = max(maxi, nums[i]);
        int cnt = 0; 
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i] == maxi)
                mp[++cnt] = i ; 
            
            if(cnt >= k)
            {
                ans += (mp[cnt-k+1]+1);
            }
        }
        return ans; 
    }
};