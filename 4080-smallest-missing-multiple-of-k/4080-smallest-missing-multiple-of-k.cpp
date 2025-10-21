class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = 0; unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]]++;
        int num = k;
        int factor = 2; 
        while(true)
        {
            if(mp.count(num) ==0)
                return num;
            num = k*factor;
            factor++;
        }
        return 0 ; 
    }
};