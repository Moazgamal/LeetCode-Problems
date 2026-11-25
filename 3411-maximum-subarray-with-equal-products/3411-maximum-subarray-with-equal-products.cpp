class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1; 
        for(int i = 0; i < nums.size()-1; i++)
        {
            double p = nums[i]*nums[i+1];
            int g = gcd(nums[i], nums[i+1]);
            int l = lcm(nums[i], nums[i+1]);
            if(p == g*l)
                ans = max(ans, 2);
            for(int j = i+2; j < nums.size(); j++)
            {
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(nums[j], l);
                if(p == g*l)
                    ans = max(ans, j-i+1);
            }
        }
        return ans; 
    }
};