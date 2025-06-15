class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9+7;
        int ans = 0; 
        unordered_map<int,int>before;
        unordered_map<int,int>after;
        vector<int>v1(nums.size());
        vector<int>v2(nums.size());
        for(int i = 0; i< nums.size(); i++)
            {
                v1[i] = before[nums[i]*2];
                before[nums[i]]++;
            }
        for(int i = nums.size()-1; i>=0; i--)
            {
                v2[i] = after[nums[i]*2];
                after[nums[i]]++;
            }
        for(int i = 0; i< v1.size(); i++)
            {
                long long f1 = v1[i]%MOD;
                long long f2 = v2[i]%MOD;
                ans += (f1%MOD*f2%MOD)%MOD;
                
                ans %= MOD;
            }
        return ans; 
        
        
        
    }
};