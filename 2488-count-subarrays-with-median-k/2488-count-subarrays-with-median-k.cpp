class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == k)
            {
                i = j; break;
            }
        }
        int ans = 0; int b1 = 0; int s1 = 0; 
        for(int j = i-1; j>=0; j--)
        {
            if(nums[j] > nums[i])
                b1++;
            else
                s1++;
            if(b1-s1 == 0 || b1-s1 == 1)
                ans++;
            mp1[b1-s1]++;
        }
        b1 = 0; s1 = 0; 
        for(int j = i+1; j<nums.size(); j++)
        {
            if(nums[j] > nums[i])
                b1++;
            else
                s1++;
            if(b1-s1 == 0 || b1-s1 == 1)
                ans++;
            if(mp1.count(-1*(b1-s1)) != 0)
                ans += mp1[-1*(b1-s1)];
            if(mp1.count(1-(b1-s1)) != 0)
                ans += mp1[1-(b1-s1)];
        }
        return ans+1; 
    }
};