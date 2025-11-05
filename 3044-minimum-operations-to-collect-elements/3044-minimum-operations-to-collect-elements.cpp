class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,bool>mp; 
        int cnt=0;
        for(int i = nums.size()-1; i >= 0; i--, cnt++)
        {
            if(nums[i] <=k)
                mp[nums[i]]=true;

            if(mp.size() == k)
                return cnt+1; 
        }
        return 0;
        
    }
};