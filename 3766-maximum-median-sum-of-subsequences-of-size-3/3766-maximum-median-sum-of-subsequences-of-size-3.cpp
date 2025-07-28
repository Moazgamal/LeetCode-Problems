class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {

        long long ans = 0; 
        sort(nums.begin(), nums.end());
        int cnt = ((int)nums.size())/3;
        int j = (int)nums.size()-2;
        while(cnt-->0)
        {
            ans += nums[j];
            j-=2;
        }
        return ans; 
        
    }
};