class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int ans = 0; int i = 0; 
        while(i < nums.size())
        {
            int num = nums[i];
            int j = i+1;
            while(j < nums.size() && nums[j]-nums[i]<=k)
            {
                j++;
            }
            ans++;
            i=j;
        }return ans; 
        
    }
};