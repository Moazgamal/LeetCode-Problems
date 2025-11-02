class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mini = INT_MAX; int maxi = INT_MIN;
        vector<int>mp(101,0);
        for(int i = 0; i< nums.size(); i++)
        {
            mini =  min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i = mini+1; i< maxi; i++)
        {
            if(mp[i] ==0)
            {
                ans.push_back(i);
            }
        }return ans; 

        
    }
};