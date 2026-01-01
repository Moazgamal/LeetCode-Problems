class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        
        long long ans = INT_MIN;
        long long coll = 0; 
        multiset<int>mt;

        for(int i = 0; i< nums.size(); i++)
        {
            mt.insert(nums[i]);
        }
        for(int i = 0; i< nums.size()-1; i++)
        {
            mt.erase(mt.find(nums[i]));
            coll += nums[i];
            ans = max(ans, coll-*mt.begin());
        }return ans; 
    }
};