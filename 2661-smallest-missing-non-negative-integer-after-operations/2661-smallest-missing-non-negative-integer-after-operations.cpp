class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                int x = ((nums[i] % value) + value) % value;
                mp[x]++;
            }
            else 
            {
                mp[nums[i]%value]++;
            }
        }
        int missing = 0; 
        while(true)
        {
            int missing2 = missing;
            if(missing2 >= value)
            {
                missing2 %= value;
            }
            if(mp.count(missing2) == 0 || mp[missing2] == 0)
                return missing;
            
            mp[missing2]--;
            missing++;
        }
        return 0; 
        
    }
};