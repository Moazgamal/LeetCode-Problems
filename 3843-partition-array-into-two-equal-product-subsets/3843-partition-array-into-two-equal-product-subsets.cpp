class Solution {
    bool fn(int idx , vector<int>&nums, long long  target,long long p1, long long p2, bool &i1, bool &i2)
    {
        if(idx >= nums.size())
        {
            if(p1 > target || p2 > target)
                 return false; 
            if(i1 == false || i2 == false)
                return false;
            
            if(p1 == p2 && p1 == target)
                return true;
            return false;
        }
        if(p1 > target || p2 > target)
            return false; 
        
        i1 = true;
        if(fn(idx+1, nums, target, p1*nums[idx], p2, i1, i2))
            return true;
        i1 = false;
        i2 = true;
        if(fn(idx+1, nums,target, p1, p2*nums[idx], i1, i2))
            return true;
       i2 = false;
        return false;
       
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {

        
       vector<int> v1;
        vector<int>v2;
        long long p1= 1; 
        long long p2 = 1; 
        bool i1 = false;
        bool i2 = false;
        return fn(0, nums, target, p1, p2, i1, i2);
        
    }
};