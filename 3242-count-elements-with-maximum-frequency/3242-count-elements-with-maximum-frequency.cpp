class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int ans = 0;
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        for(int i =0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int maxi = 0; 
        for(auto x: mp)
        {
            maxi = max(maxi, x.second);
            mp2[x.second]++;
        }
        return mp2[maxi]*maxi;
    }
};