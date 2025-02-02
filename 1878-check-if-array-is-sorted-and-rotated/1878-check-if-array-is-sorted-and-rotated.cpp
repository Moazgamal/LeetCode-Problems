class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        if(nums2==nums)
            return true;
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0; i< nums2.size(); i++)
        {
            if(i+1 < nums2.size())
            {
                if(nums2[i+1] != nums2[i])
                    mp[nums2[i]].second = nums2[i+1];
            }
            else
            {
                if(nums2[i] != nums2[0])
                    mp[nums2[i]].second= nums2[0];
            }
            if(i-1 >=0)
            {
                if(nums2[i-1] != nums2[i])
                    mp[nums2[i]].first= nums2[i-1];
            }
            else
            {
                if(nums2[i] != nums2[nums2.size()-1])
                    mp[nums2[i]].first = nums2[nums2.size()-1];
            }
        }
        for(int i = 0; i< nums.size(); i++)
        {
            if(i+1 < nums.size())
            {
                if(nums[i+1] != nums[i])
                {
                    if(mp[nums[i]].second != nums[i+1])
                        return false;
                }
            }
            else
            {
                if(nums[0] != nums[i])
                {
                    if(mp[nums[i]].second != nums[0])
                        return false;
                }
            }
            if(i-1>=0)
            {
                if(nums[i-1] != nums[i])
                {
                    if(mp[nums[i]].first != nums[i-1])
                        return false;
                }
            }
            else
            {
                if(nums[nums.size()-1] != nums[i])
                {
                    if(mp[nums[i]].first != nums[nums.size()-1])
                        return false;
                }
            }
        }return true;
        

        
    }
};