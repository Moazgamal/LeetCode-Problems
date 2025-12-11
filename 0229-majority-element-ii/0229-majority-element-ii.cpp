class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        double sz = nums.size(); 
        sz = sz/3;
        unordered_map<int,int>mp;
        for(int i =0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto x: mp)
        {
            if(x.second > sz)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};