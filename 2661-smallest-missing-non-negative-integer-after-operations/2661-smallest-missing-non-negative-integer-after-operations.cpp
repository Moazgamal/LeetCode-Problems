class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp; int i = 0; int sz = (int)nums.size();
        while(i < sz)
        {
            if(nums[i] < 0)
                mp[((nums[i] % value) + value) % value]++;
            else 
                mp[nums[i]%value]++;
            i++;
        }
        int missing = 0; 
        while(true)
        {
            int missing2 = missing;
            if(missing2 >= value)
                missing2 %= value;
            if(mp.count(missing2) == 0 || mp[missing2] == 0)
                return missing;
            mp[missing2]--;
            missing++;
        }
        return 0; 
        
    }
};