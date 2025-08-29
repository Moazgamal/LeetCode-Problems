class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        if(nums.size()%k !=0)
            return false;
        int x = nums.size()/k;
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]> x)
                return false; 
        }
        return true; 
        
    }
};