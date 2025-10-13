class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {

        int ans = 0; unordered_map<int,int>mp;
        int i = 0; 
        while(i < nums.size())
            mp[nums[i++]]++;
            
        for(auto x: mp)
            if(x.second%k == 0)
                ans+= x.first*x.second;
        return ans; 
        
        
    }
};