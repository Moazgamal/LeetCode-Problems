class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans= 0; 
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = i+1; j< nums.size(); j++)
            {
                int prod = nums[i]* nums[j];
                if(mp.count(prod) != 0)
                {
                    ans+=(mp[prod] * 8);
                }
                mp[prod]++;
            }
        }return ans;
    }
};