class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> indicies;
        for(int i = 0; i< nums.size(); i++)
        {
            if(indicies.count(nums[i]) >0)
            {
                if(i-indicies[nums[i]] <= k)
                    return true;
            }
            indicies[nums[i]]=i;
        }return false;
        
    }
};