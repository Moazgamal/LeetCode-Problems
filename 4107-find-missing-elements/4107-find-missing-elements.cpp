class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mini = INT_MAX; int maxi = INT_MIN;
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            mini =  min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i = mini+1; i< maxi; i++)
        {
            if(mp.count(i) ==0)
            {
                ans.push_back(i);
            }
        }return ans; 

        
    }
};