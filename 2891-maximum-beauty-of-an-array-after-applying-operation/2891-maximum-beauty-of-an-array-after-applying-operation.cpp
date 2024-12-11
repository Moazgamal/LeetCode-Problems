class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        vector<int> v (3*100000+4,0);
        for(int i = 0; i< nums.size(); i++)
        {
            v[nums[i]-k+100000]++;
            v[nums[i]+k+1+100000]--;
        }
        int prefix = 0; 
        int ans = 0; 
        for(auto it : v)
        {
            prefix += it;
            ans = max(ans, prefix);
        }return ans;
        
    }
};