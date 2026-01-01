class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        
        long long ans = INT_MIN;
        long long coll = 0; 
        // multiset<int>mt;
        vector<int>suffix(nums.size(), INT_MAX);
        suffix[suffix.size()-1]= nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--)
        {
            suffix[i] = min(nums[i], suffix[i+1]);
        }
        for(int i = 0; i< nums.size()-1; i++)
        {
            // mt.erase(mt.find(nums[i]));
            coll += nums[i];
            ans = max(ans, coll-suffix[i+1]);
        }return ans; 
    }
};