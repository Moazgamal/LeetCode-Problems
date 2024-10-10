class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int ans= 0;
        int curr = 0;
        vector<int> minis; minis.push_back(0);
        for(int i  =1; i< nums.size(); i++)
        {
            
            int j  = minis.size()-1;
            if(nums[i] < nums[minis[j]])
            {
                minis.push_back(i);
                continue;
            }
            while(j>=0&&nums[i] >= nums[minis[j]])
            {
                ans = max(ans, i-minis[j]);
                j--;
            }
            
        }return ans;
        
    }
};