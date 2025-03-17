class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int sz = nums.size(); 
        sz = sz/2;
        unordered_map<int,int> freq;
        for(int i = 0; i< nums.size(); i++)
        {
            ++freq[nums[i]];
        }
        for(auto x: freq)
        {
            if(x.second>= 2)
                if(x.second%2==0)
                    continue;
            return false;
        }return true;
    }
};