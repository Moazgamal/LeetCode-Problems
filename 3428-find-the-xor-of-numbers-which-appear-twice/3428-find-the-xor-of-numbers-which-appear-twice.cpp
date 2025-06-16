class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        vector<int>v(51,0);
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]++;
            if(v[nums[i]]==2)
                ans^=nums[i];
        }return ans; 
        
    }
};