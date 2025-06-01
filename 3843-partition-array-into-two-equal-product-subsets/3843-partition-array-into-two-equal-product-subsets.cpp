class Solution {
    bool fn(int idx , vector<int>&nums, long long  target,long long p1, long long p2, vector<int>&v1, vector<int>&v2)
    {
        if(idx >= nums.size())
        {
            if(p1 > target || p2 > target)
                 return false; 
            if(v1.size() == 0 || v2.size() == 0)
                return false;
            
            if(p1 == p2 && p1 == target)
                return true;
            return false;
        }
        if(p1 > target || p2 > target)
            return false; 
        
        
        v1.push_back(nums[idx]);
        if(fn(idx+1, nums, target, p1*nums[idx], p2, v1, v2))
            return true;
        v1.pop_back();
        v2.push_back(nums[idx]);
        if(fn(idx+1, nums,target, p1, p2*nums[idx], v1, v2))
            return true;
        v2.pop_back();
        return false;
       
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {

        
       vector<int> v1;
        vector<int>v2;
        long long p1= 1; 
        long long p2 = 1; 
        return fn(0, nums, target, p1, p2, v1, v2);
        
    }
};