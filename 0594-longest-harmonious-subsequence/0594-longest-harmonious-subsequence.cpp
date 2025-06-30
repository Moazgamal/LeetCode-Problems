class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x: nums)
            mp[x]++;
        int ans = 0; 
        for(auto x: mp)
        {
            if(mp.count(x.first-1)!=0)
            {
                ans = max(ans, x.second+mp[x.first-1]);
            }
            if(mp.count(x.first+1)!=0)
            {
                ans = max(ans, x.second+mp[x.first+1]);
            }
        }return ans; 
        
    }
};