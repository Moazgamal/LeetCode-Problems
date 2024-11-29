class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> occ;
        for(int i = 0; i< nums.size(); i++)
        {
            if(++occ[nums[i]]>1)
                return true;
        }
        return false;
    }
};